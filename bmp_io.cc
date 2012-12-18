// Reference used for the BMP file format(s):
// http://www.fileformat.info/format/bmp/egff.htm

#include "bmp_io.hh"

#include <cassert>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

namespace {

  // Substitute cstdint header declarations.
  typedef unsigned short uint_least16_t;
  typedef short int16_t;
  typedef unsigned int uint_least32_t;
  typedef int int32_t;
  typedef int int_least32_t;

  uint_least16_t read_WORD(istream &stream)
  {
    assert(sizeof(uint_least16_t) >= 2);
    uint_least16_t value = 0;
    value |= stream.get();
    value |= static_cast<uint_least16_t>(stream.get()) << 8;
    return value;
  }

  uint_least32_t read_DWORD(istream &stream)
  {
    assert(sizeof(uint_least32_t) >= 4);
    uint_least32_t value = 0;
    value |= stream.get();
    value |= static_cast<uint_least32_t>(stream.get()) << 8;
    value |= static_cast<uint_least32_t>(stream.get()) << 16;
    value |= static_cast<uint_least32_t>(stream.get()) << 24;
    return value;
  }

  int16_t read_SHORT(istream &stream)
  {
    assert(sizeof(int16_t) == 2);
    int16_t value = 0;
    value |= stream.get();
    value |= static_cast<int16_t>(stream.get()) << 8;
    return value;
  }
  int32_t read_LONG(istream &stream)
  {
    assert(sizeof(int32_t) == 4);
    int32_t value = 0;
    value |= stream.get();
    value |= static_cast<int32_t>(stream.get()) << 8;
    value |= static_cast<int32_t>(stream.get()) << 16;
    value |= static_cast<int32_t>(stream.get()) << 24;
    return value;
  }

} // empty namespace


BmpData::BmpData(string const &file_name)
{
  ifstream stream(file_name.c_str(), ios_base::in | ios_base::binary);

  if(stream.fail()) {
    string message = strerror(errno);
    clog << "Input file '" << file_name << "' could not be opened ("
         << message << "), aborting." << endl;
    exit(EXIT_FAILURE);
  }

  assert(stream.good());
  try {
    stream.exceptions(ios_base::eofbit | ios_base::failbit | ios_base::badbit);

    // File offset 0, beginning of first header (File Header).
    // File offset 0, read magic string (FileType field).
    if(stream.get() != 'B' || stream.get() != 'M') {
      clog << "Input file '" << file_name << "' is not in BMP format." << endl;
      exit(EXIT_FAILURE);
    }

    // File offset 2, skip fields FileSize, Reserved1, Reserved2.
    stream.ignore(8);

    // File offset 10, read BitmapOffset (in endian-independent fashion).
    uint_least32_t data_offset = read_DWORD(stream);

    // File offset 14, beginning of second header (Bitmap Header).
    // File offset 14, read size of header.
    uint_least32_t size_of_header = read_DWORD(stream);

    assert(sizeof(int_least32_t) >= 4);
    int_least32_t width, height;
    if(size_of_header == 12) {
      // File offset 18, read width and height.
      width = read_SHORT(stream);
      height = read_SHORT(stream);
    } else {
      // File offset 18, read width and height.
      width = read_LONG(stream);
      height = read_LONG(stream);
    }

    // File offset [22 / 26], ignore Planes field.
    stream.ignore(2);
    // File offset [24 / 28], read BitsPerPixel.
    if(read_WORD(stream) != 24) {
      clog << "The BMP file '" << file_name << "'cannot be read: "
        "it must be stored in 24-bit RGB format." << endl;
      exit(EXIT_FAILURE);
    }

    if(size_of_header == 12) {
      // File offset 26, past the end of header.
      stream.ignore(data_offset - 26);
    } else {
      // File offset 26, read Compression.
      if(read_DWORD(stream) != 0) {
      clog << "The BMP file '" << file_name << "'cannot be read: "
        "it uses compression, which is not handled." << endl;
      exit(EXIT_FAILURE);
      }

      // File offset 30, past any interesting header field.
      stream.ignore(data_offset - 30);
    }
  } catch(const ios_base::failure &exception) {
    clog << "Error reading the BMP header of '" << file_name << "' ("
         << exception.what() << "), aborting." << endl;
    exit(EXIT_FAILURE);
  }

  try {
    stream.exceptions(ios_base::failbit | ios_base::badbit);

  } catch(const ios_base::failure &exception) {
    clog << "Error reading the BMP image data in '" << file_name << "' ("
         << exception.what() << "), aborting." << endl;
    exit(EXIT_FAILURE);
  }

  stream.close();
}
