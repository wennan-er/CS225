#include <iostream>
#include "StickerSheet.h"
#include <algorithm>

#include <string>

StickerSheet::StickerSheet(const Image & picture, unsigned max){
  base_ = new Image(picture);  //make a copy of picture
  max_ = max;
  stickers_ = new Image * [max_];
  for (unsigned int i = 0; i < max_ ;i++){
    stickers_[i] = NULL;

  }
  arrayx_ = new unsigned[max_];
  arrayy_ = new unsigned[max_];
  count_ = 0;
}

StickerSheet::~StickerSheet(){
  destroy();
}

StickerSheet::StickerSheet(const StickerSheet & other){
  copy(other);
}

const StickerSheet & StickerSheet::operator = (const StickerSheet & other){
  if (this != &other){
    destroy();
    copy(other);
  }
  return *this;
}

void StickerSheet::changeMaxStickers(unsigned max){
//make a new one with max
 if (max != max_){
  Image ** sti_temp_array = new Image * [max];
  for (unsigned i = 0; i < max ;i++){
    sti_temp_array[i] = NULL;
  }

  unsigned * tempx = new unsigned[max];
  unsigned * tempy = new unsigned[max];

  unsigned range = std::min(int(max),int(this->count_));

  for (unsigned i = 0; i < range;i++){
    sti_temp_array[i] = new Image(*(stickers_[i]));
    tempx[i] = arrayx_[i];
    tempy[i] = arrayy_[i];
  }
  max_ = max;




//delete original
  for (int i = 0; i < int(this->count_);i++){
    if (stickers_[i]!=NULL){
      delete stickers_[i];
    }
  }
  count_ = range;
  if(count_ ==0){
    delete [] stickers_;
  }
  delete [] stickers_;
  //stickers_ = NULL;
  delete [] arrayx_;
  delete [] arrayy_;

  //copy the new one to original
    this->stickers_ = sti_temp_array;
    arrayx_ = tempx;
    arrayy_ = tempy;

}
}



int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){

  if (count_ < max_){
    stickers_[count_] = new Image(sticker);
    arrayx_[count_] = x;
    arrayy_[count_] = y;
    count_++;
    return count_ -1;
  }
  return -1;
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){


  if (index <= count_){
    arrayx_[index] = x;
    arrayy_[index] = y;
    return true;
  }
  return false;
}

void StickerSheet::removeSticker(unsigned index){
  if (index <= count_){
    delete stickers_[index];
    stickers_[index] = NULL;
    for(int i = index; i < int(count_)-1; i++){

      stickers_[i] = stickers_[i+1];
      arrayx_[i] = arrayx_[i+1];
      arrayy_[i] = arrayy_[i+1];

    }
    arrayx_[count_-1] = 0;
    arrayy_[count_-1] = 0;
    stickers_[count_-1] = NULL;
  }
  count_--;
}

Image * StickerSheet::getSticker(unsigned index){
  if (index <= count_){
    return stickers_[index];

  }
  return NULL;
}


Image StickerSheet::render() const{
  Image final(*(base_));
  unsigned max_x = final.width();
  unsigned max_y = final.height();
  for (unsigned int i = 0; i < count_ ; i++){
    if(stickers_[i]->width() + arrayx_[i] > max_x ){
      max_x = stickers_[i]->width() + arrayx_[i];
    }
    if(stickers_[i]->height() + arrayy_[i] > max_y){
      max_y = stickers_[i]->height() + arrayy_[i];
    }
  }
  final.resize(max_x,max_y);
  for (int i=0; i<int(count_);i++){

    //add every sticker to final picture
    for (unsigned x = 0; x < stickers_[i]->width(); x++) {
      for (unsigned y = 0; y < stickers_[i]->height(); y++) {
        cs225::HSLAPixel & pixelcover = stickers_[i]->getPixel(x, y);
        cs225::HSLAPixel & pixelbase = final.getPixel(x+arrayx_[i], y+arrayy_[i]);
        if (pixelcover.a != 0){
          pixelbase = pixelcover;
        }
      }
    }
    //end the process of stickers_[i]
  }
  //end the process for all stickers in stickers_
  return final;
}



void StickerSheet::destroy(){
  delete [] arrayx_;
  delete [] arrayy_;
  delete base_;
  for (int i = 0; i < int(this->count_);i++){
    if (stickers_[i]!=NULL){
      delete stickers_[i];
    }

  }
  delete []stickers_;

}

void StickerSheet::copy(const StickerSheet &other){
  base_ = new Image(*(other.base_));
  max_ = other.max_;
  stickers_ = new Image*[max_];
  for (unsigned int i = 0; i < max_ ;i++){
    stickers_[i] = NULL;
  }
  arrayx_ = new unsigned[max_];
  arrayy_ = new unsigned[max_];
  count_ = 0;

  for (int i=0; i < int(other.count_);i++){
    //Image * stick_temp = new Image(*(other.stickers_[i]));
    //stickers_[i] = stick_temp;
    //stick_temp = NULL;

    stickers_[i]= new Image(*(other.stickers_[i]));
    arrayx_[i] = other.arrayx_[i];
    arrayy_[i] = other.arrayy_[i];
    count_++;
  }

}
