/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>
#include <iostream>
using std::string;
using std::vector;
using std::ifstream;
using std::sort;
/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
 //std::map<std::string, std::vector<std::string>> dict;
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    ifstream wordsFile(filename);
    string word;
    if (wordsFile.is_open()) {
    /* Reads a line from `wordsFile` into `word` until the file ends. */
        while (getline(wordsFile, word)) {
          if (dict.find(checksort(word)) != dict.end()){
              dict[checksort(word)].push_back(word);
            }else{
              vector<string> tmp;
              tmp.push_back(word);
              dict.insert({checksort(word),tmp});
            }

        }
      }
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
    for (auto it = words.begin(); it != words.end(); it++){
      string word = *it;
      if (dict.find(checksort(word)) != dict.end()){
          dict[checksort(word)].push_back(word);
        }else{
          vector<string> tmp;
          tmp.push_back(word);
          dict.insert({checksort(word),tmp});
          //std::cout << tmp[0] << std::endl;
        }
    }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    if (dict.find(checksort(word)) == dict.end()) return vector<string>();
    return dict.at(checksort(word));
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    vector<vector<string>> ret;
    for (auto it = dict.begin(); it!= dict.end(); it++){
      if (dict.at(it->first).size() > 1)
      ret.push_back(dict.at(it->first));
    }
    return ret;
}

string AnagramDict::checksort(const string& word) const{
  string Word = word;
  sort(Word.begin(), Word.end());
  return Word;
}
