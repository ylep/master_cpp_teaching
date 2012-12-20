// Reference used for the BMP file format(s):
// http://www.fileformat.info/format/bmp/egff.htm

#include "bmp_io.hh"

#include <cassert>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

namespace {

  // Substitute cstdint header declarations.
  typedef short int16_t;
  typedef long int32_t;
  typedef unsigned short uint_least16_t;
  typedef unsigned long uint_least32_t;
  typedef long int_least32_t;

#if CHAR_BIT != 8
#error This code assumes that chars are exactly 8 bit.
#endif

  void check_int_sizes() {
    static bool ok = false;
    if(!ok) {
      assert(sizeof(uint_least16_t) >= 2);
      assert(sizeof(int16_t) == 2);
      assert(sizeof(uint_least32_t) >= 4);
      assert(sizeof(int32_t) == 4);
      assert(sizeof(int_least32_t) >= 4);
      ok = true;
    }
  }

  uint_least16_t read_WORD(istream &stream)
  {
    uint_least16_t value = 0;
    value |= stream.get();
    value |= static_cast<uint_least16_t>(stream.get()) << CHAR_BIT;
    return value;
  }

  uint_least32_t read_DWORD(istream &stream)
  {
    uint_least32_t value = 0;
    value |= stream.get();
    value |= static_cast<uint_least32_t>(stream.get()) << CHAR_BIT;
    value |= static_cast<uint_least32_t>(stream.get()) << (2 * CHAR_BIT);
    value |= static_cast<uint_least32_t>(stream.get()) << (3 * CHAR_BIT);
    return value;
  }

  int16_t read_SHORT(istream &stream)
  {
    int16_t value = 0;
    value |= stream.get();
    value |= static_cast<int16_t>(stream.get()) << CHAR_BIT;
    return value;
  }
  int32_t read_LONG(istream &stream)
  {
    int32_t value = 0;
    value |= stream.get();
    value |= static_cast<int32_t>(stream.get()) << CHAR_BIT;
    value |= static_cast<int32_t>(stream.get()) << (2 * CHAR_BIT);
    value |= static_cast<int32_t>(stream.get()) << (3 * CHAR_BIT);
    return value;
  }

} // empty namespace


BmpData::BmpData(const string &file_name)
{
  ifstream stream(file_name.c_str(), ios_base::in | ios_base::binary);

  if(stream.fail()) {
    string message = strerror(errno);
    clog << "Input file '" << file_name << "' could not be opened ("
         << message << "), aborting." << endl;
    exit(EXIT_FAILURE);
  }

  bool read_lines_backward = read_header(file_name, stream);

  size_t line_size = (width() * 3 + 3) % 4;

  try {
    
  } catch(const ios_base::failure &exception) {
    if(stream.eof()) {
      clog << "Error reading the BMP image data in '" << file_name
           << "': premature end of file, aborting." << endl;
    } else {
      clog << "Error reading the BMP image data in '" << file_name << "' ("
           << exception.what() << "), aborting." << endl;
    }
    exit(EXIT_FAILURE);
  }

  stream.close();
}

bool BmpData::read_header(const std::string &file_name, istream &stream)
{
  check_int_sizes();
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
    size_t data_offset = read_DWORD(stream);

    // File offset 14, beginning of second header (Bitmap Header).
    // File offset 14, read size of header.
    size_t size_of_header = read_DWORD(stream);

    int_least32_t int_width, int_height;
    if(size_of_header == 12) {
      // File offset 18, read width and height.
      int_width = read_SHORT(stream);
      int_height = read_SHORT(stream);
    } else {
      // File offset 18, read width and height.
      int_width = read_LONG(stream);
      int_height = read_LONG(stream);
    }

    if(int_width <= 0) {
      clog << "Invalid BMP file '" << file_name
           << "': width is negative, aborting." << endl;
    }
    m_width = int_width;
    if(int_height > 0) {
      m_height = int_height;
    } else if(int_height < 0) {
      m_height = -int_height;
    } else {
      clog << "Invalid BMP file '" << file_name
           << "': height is zero, aborting." << endl;
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

    return int_height < 0;
  } catch(const ios_base::failure &exception) {
    clog << "Error reading the BMP header of '" << file_name << "' ("
         << exception.what() << "), aborting." << endl;
    exit(EXIT_FAILURE);
  }
}
