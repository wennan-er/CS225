#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>

using std::string;

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */

string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    HuffmanNode current = huffmanTree[0];
    for (const char& c : binaryString) {
      if (current.left_==NULL & current.right_==NULL){
        current.char_; 
      }
      if (c==0){
        current = current.left_;
      }else{
        current = current.right_;
      }

}
    return "";
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */

string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    return "";
}
