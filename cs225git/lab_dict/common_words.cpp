/**
 * @file common_words.cpp
 * Implementation of the CommonWords class.
 *
 * @author Zach Widder
 * @date Fall 2014
 */

#include "common_words.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;

string remove_punct(const string& str)
{
    string ret;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(ret),
                        std::ptr_fun<int, int>(&std::ispunct));
    return ret;
}

CommonWords::CommonWords(const vector<string>& filenames)
{
    // initialize all member variables
    init_file_word_maps(filenames);
    init_common();
}

void CommonWords::init_file_word_maps(const vector<string>& filenames)
{
    // make the length of file_word_maps the same as the length of filenames
    file_word_maps.resize(filenames.size());
    num = filenames.size();

    // go through all files
    for (size_t i = 0; i < filenames.size(); i++) {
        // get the corresponding vector of words that represents the current
        // file
        vector<string> words = file_to_vector(filenames[i]);
        /* Your code goes here! */
        std::map<string, unsigned int> &mymap = file_word_maps[i];
        for (size_t j = 0; j < words.size(); j++) {
          if (mymap.find(words[j]) != mymap.end())  mymap[words[j]]++;
          else mymap[words[j]]=1;
        }
    }
}
//* #common maps a word to the number of documents that word appears in
//std::map<std::string, unsigned int> common;
void CommonWords::init_common()
{
    /* Your code goes here! */
    for (size_t i = 0; i < file_word_maps.size(); i++) {
      std::map<string, unsigned int> m = file_word_maps[i];
      for (auto it = m.begin(); it != m.end(); it++){
          if (common.find(it->first) != common.end()) common[it->first]++;
          else common[it->first] = 1;
        }
    }
}

/**
 * @param n The number of times to word has to appear.
 * @return A vector of strings. The vector contains all words that appear
 * in each file >= n times.
 */
vector<string> CommonWords::get_common_words(unsigned int n) const
{
    vector<string> out;
    /* Your code goes here! */
    for (auto it = common.begin(); it != common.end(); it++) {
      string word = it->first;
      unsigned int count = it->second;
      if (count < num) continue;
      else{
        size_t i = 0;
        while (i < file_word_maps.size()){
          std::map<string, unsigned int> m = file_word_maps[i];
          if (m[word] < n) break;
          else i++;
        }
        if (i == file_word_maps.size()) out.push_back(word);

      }
    }
    return out;
}

/**
 * Takes a filename and transforms it to a vector of all words in that file.
 * @param filename The name of the file that will fill the vector
 */
vector<string> CommonWords::file_to_vector(const string& filename) const
{
    ifstream words(filename);
    vector<string> out;

    if (words.is_open()) {
        std::istream_iterator<string> word_iter(words);
        while (!words.eof()) {
            out.push_back(remove_punct(*word_iter));
            ++word_iter;
        }
    }
    return out;
}
