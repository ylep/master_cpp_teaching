#include <cstdlib>
#include <iostream>

#include "bmp_io.hh"

using namespace std;

int main(int argc, char **argv)
{
  if(argc < 3) {
    clog << "Usage: test input.bmp output.bmp" << endl;
    return EXIT_FAILURE;
  }

  BmpData bmp_data(argv[1]);

  cout << "Width: " << bmp_data.width() << '\n';
  cout << "Height: " << bmp_data.height() << '\n';
  cout << "First pixel (bottom left): B=" << int(bmp_data.data()[0])
       << ", G=" << int(bmp_data.data()[1])
       << ", R=" << int(bmp_data.data()[2]) << endl;

  // beware of short-circuit
  bool ok = bmp_data.write_file(argv[2]) && cout.good();

  return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
