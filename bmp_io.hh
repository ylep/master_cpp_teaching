#ifndef _BMP_IO_HH_INCLUDED_
#define _BMP_IO_HH_INCLUDED_

#include <string>

class BmpData
{
public:
  /* Load the named BMP file. In case of failure a message is printed and the
     program is exited. */
  explicit BmpData(std::string const &file_name);

  unsigned int size_x() const {return m_size_x;};
  unsigned int size_y() const {return m_size_y;};

  const unsigned char * data() const {return m_data;};
  unsigned char * data() {return m_data;};

private:
  unsigned int m_size_x, m_size_y;
  unsigned char *m_data;
};

#endif // !defined(_BMP_IO_HH_INCLUDED_)
