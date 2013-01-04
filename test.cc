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

  Bmp24 input_bmp(argv[1]);
  size_t width = input_bmp.width();
  size_t height = input_bmp.height();
  unsigned char const * const input_data = input_bmp.data();

  cout << "Width: " << width << '\n';
  cout << "Height: " << height << '\n';
  cout << "First pixel (bottom left): B=" << int(input_data[0])
       << ", G=" << int(input_data[1])
       << ", R=" << int(input_data[2]) << endl;

  Bmp24 output_bmp(width, height);
  unsigned char * const output_data = output_bmp.data();

  for(size_t pixel_index = 0 ; pixel_index < width * height ; ++pixel_index) {
    output_data[3 * pixel_index] = input_data[3 * pixel_index];
    output_data[3 * pixel_index + 1] = input_data[3 * pixel_index + 1];
    output_data[3 * pixel_index + 2] = input_data[3 * pixel_index + 2];
  }

  // beware of short-circuit
  bool ok = output_bmp.write_file(argv[2]) && cout.good();

  return ok ? EXIT_SUCCESS : EXIT_FAILURE;
}
