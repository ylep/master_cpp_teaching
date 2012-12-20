#ifndef _BMP_IO_HH_INCLUDED_
#define _BMP_IO_HH_INCLUDED_

#include <string>
#include <iosfwd>

class BmpData
{
public:
  /* Load the named BMP file. In case of failure a message is printed and the
     program is exited. */
  explicit BmpData(std::string const &file_name);
  BmpData(size_t width, size_t height);
  ~BmpData();

  size_t width() const {return m_width;};
  size_t height() const {return m_height;};

  const unsigned char * data() const {return m_data;};
  unsigned char * data() {return m_data;};

  bool write_file(std::string const &file_name) const;

private:
  size_t m_width, m_height;
  unsigned char *m_data;

  // Prevent copy and assignment
  BmpData(const BmpData &);
  BmpData & operator=(const BmpData &);

  // Helper method for internal use only
  bool read_header(const std::string&, std::istream&);
};

#endif // !defined(_BMP_IO_HH_INCLUDED_)
