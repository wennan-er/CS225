#include "Image.h"
#include <algorithm>
#include <iostream>
#include <math.h>
/*Image::Image(unsigned int width, unsigned int height){
  cs225::PNG(width, height);
};
*/


void Image::lighten(){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      cs225::HSLAPixel & pixel = getPixel(x, y);
       pixel.l = std::min(pixel.l+0.1,1.0);
  }
}
};
void Image::lighten(double amount){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      cs225::HSLAPixel & pixel = getPixel(x, y);
       pixel.l = std::min(pixel.l+amount,1.0);
        }
      }
  };
void Image::darken(){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      cs225::HSLAPixel & pixel = getPixel(x, y);
       pixel.l = std::max(pixel.l-0.1,0.0);
        }
      }
  };
void Image::darken(double amount){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      cs225::HSLAPixel & pixel = getPixel(x, y);
       pixel.l = std::max(pixel.l-amount,0.0);
        }
      }
  };
void Image::saturate(){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      cs225::HSLAPixel & pixel = getPixel(x, y);
       pixel.s = std::min(pixel.s+0.1,1.0);
        }
      }
  };
void Image::saturate(double amount){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      cs225::HSLAPixel & pixel = getPixel(x, y);
       pixel.s = std::min(pixel.s+amount,1.0);
        }
      }
  };
void Image::desaturate(){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      cs225::HSLAPixel & pixel = getPixel(x, y);
       pixel.s = std::max(pixel.s-0.1,0.0);
        }
      }
  };
void Image::desaturate(double amount){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      cs225::HSLAPixel & pixel = getPixel(x, y);
       pixel.s = std::max(pixel.s-amount,0.0);
        }
      }
  };
void Image::grayscale(){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      cs225::HSLAPixel & pixel = getPixel(x, y);
       pixel.s = 0;
        }
      }
  };
void Image::rotateColor(double degrees){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      cs225::HSLAPixel & pixel = getPixel(x, y);
      double newcolor = pixel.h + degrees;
      if (newcolor > 360){
        newcolor = newcolor - 360;
      }
      if (newcolor < 0){
        newcolor = newcolor + 360;
      }
      pixel.h = newcolor;

        }
      }
  };

void Image::illinify(){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      cs225::HSLAPixel & pixel = getPixel(x, y);

     if (pixel.h > 293 || pixel.h < 114){
      pixel.h = 11;
      }else{
      pixel.h = 216;
       }
     }
  }
};
void Image::scale(double factor){

  PNG *output = new PNG(factor * this->width(), factor * this->height());
  for (unsigned x = 0; x < output->width(); x++) {
    for (unsigned y = 0; y < output->height(); y++) {


      cs225::HSLAPixel & pixelout = output->getPixel(x, y);
      cs225::HSLAPixel & pixel = getPixel(floor(x/factor),floor(y/factor));
      pixelout.h = pixel.h;
      pixelout.s = pixel.s;
      pixelout.l = pixel.l;
      pixelout.a = pixel.a;
    }
  }

  this->resize(factor*this->width(), factor * this->height());
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixelout = output->getPixel(x, y);
      cs225::HSLAPixel & pixel = getPixel(x,y);
      pixel.h = pixelout.h;
      pixel.s = pixelout.s;
      pixel.l = pixelout.l;
      pixel.a = pixelout.a;
   }
    }

   delete output;



}
void Image::scale(unsigned w, unsigned h){
  double scale1 = (double) w/width();
  double scale2 = (double) h/height() ;
  double fac = std::min(scale1,scale2);
  scale(fac);

  //unsigned int newwidth = floor(width() * fac);
  //unsigned int newheight = floor(height() * fac);

  /*PNG *output = new PNG(floor(width() * fac), floor(height() * fac));
  for (unsigned x = 0; x < output->width(); x++) {
    for (unsigned y = 0; y < output->height(); y++) {
      cs225::HSLAPixel & pixelout = output->getPixel(x, y);
      unsigned int x1 = floor(x*fac);
      unsigned int y1 = floor(y*fac);
      cs225::HSLAPixel & pixel = getPixel(x1,y1);
      pixelout.h = pixel.h;
      pixelout.s = pixel.s;
      pixelout.l = pixel.l;
      pixelout.a = pixel.a;
    }
  }
  this->resize(fac*this->width(), fac * this->height());
  for (unsigned x = 0; x < this->width(); x++) {
    for (unsigned y = 0; y < this->height(); y++) {
      cs225::HSLAPixel & pixelout = output->getPixel(x, y);
      cs225::HSLAPixel & pixel = getPixel(x,y);
      pixel.h = pixelout.h;
      pixel.s = pixelout.s;
      pixel.l = pixelout.l;
      pixel.a = pixelout.a;

    }
  }
  delete output;
  */
};
