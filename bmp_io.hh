#ifndef _BMP_IO_HH_INCLUDED_
#define _BMP_IO_HH_INCLUDED_

#include <string>
#include <iosfwd>

class Bmp24
{
public:
  /* Load the BMP file whose name is passed as argument. In case of failure a
     message is printed to standard error and the program is exited. */
  explicit Bmp24(std::string const &file_name);

  /* Create a BMP image of specified width and height. Memory is allocated to
     hold the corresponding image data, its address is accesible using
     data(). */
  Bmp24(size_t width, size_t height);
  ~Bmp24();

  size_t width() const {return m_width;};
  size_t height() const {return m_height;};

  const unsigned char * data() const {return m_data;};
  unsigned char * data() {return m_data;};

  bool write_file(std::string const &file_name) const;

private:
  size_t m_width, m_height;
  unsigned char *m_data;

  // Prevent copy and assignment
  Bmp24(const Bmp24 &);
  Bmp24 & operator=(const Bmp24 &);

  // Helper method for internal use only
  bool read_header(const std::string&, std::istream&);
};

#endif // !defined(_BMP_IO_HH_INCLUDED_)
