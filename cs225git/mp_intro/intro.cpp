#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>
#include <iostream>
#include <cmath>
using namespace cs225;

void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2
  PNG rotateImage;
  rotateImage.readFromFile(inputFile);

  unsigned width = rotateImage.width();
  unsigned height = rotateImage.height();

  PNG outputImage = PNG(width,height);
  for (unsigned x = 0; x < width; x++) {
  for (unsigned y = 0; y < height; y++) {

    HSLAPixel & pixel = rotateImage.getPixel(x, y);
    HSLAPixel & outpixel = outputImage.getPixel(width-1-x, height-1-y);
    outpixel = pixel ;

  }
}
  outputImage.writeToFile(outputFile);

}

double mapToReal(int x, int width, double minR, double maxR){
  double range = maxR - minR;
  return x * (range/width) + minR;
}

double mapToImaginary(int y, int height, double minI, double maxI){
  double range = maxI - minI;
  return y * (range/height) + minI;
}

int findMandelbrot(double cr, double ci, int max_iterations){
  int i = 0;
  double zr = 0.0, zi = 0.0;
  while (i < max_iterations && zr *zr +zi * zi < 4.0){
    double temp = zr * zr - zi * zi +cr;
    zi = 2.0 * zr * zi +ci;
    zr = temp;
    i++;
  }
  return i;
}
double minR = -1.5;
double maxR = 0.7;
double minI = -1.0;
double maxI = 1.0;
int maxN = 255;

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3
  for (unsigned int y = 0; y < height; y++){
    for (unsigned int x = 0; x < width; x++){
      HSLAPixel & pixel = png.getPixel(x, y);
      //find the real and imaginary values for c
      double cr = mapToReal(x, width, minR, maxR);
      double ci = mapToImaginary(y, height, minI, maxI);

      //find the number of iterations in the Mandelbrot
      int n = findMandelbrot(cr, ci, maxN);
      double m = 1000*cos(n)*sin(n);

      //map the resulting number to png value
      int color = ((int)(n*m) % 256);
      pixel.h = color;
      pixel.s = 0.8;
      pixel.l = 0.6;
      pixel.a = 0.7;

      //output the image
    }
  }

  return png;
}
