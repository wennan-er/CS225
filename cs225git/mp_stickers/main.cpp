#include "Image.h"
#include "StickerSheet.h"
#include <iostream>
int main() {
  Image base;     base.readFromFile("base.png");
  Image panda;    panda.readFromFile("panda.png");
  Image brown;    brown.readFromFile("brown.png");
  Image ice;      brown.readFromFile("ice.png");
  Image brownbear;      brownbear.readFromFile("brownbear.png");

  StickerSheet sheet(base, 10);
  sheet.addSticker(panda, 200, 600);

  sheet.addSticker(ice, 600, 550);
  sheet.addSticker(brown, 450, 650);
  sheet.addSticker(brownbear, 650, 600);



  sheet.render().writeToFile("myImage.png");

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  return 0;
}
