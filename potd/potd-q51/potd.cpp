#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <iterator>
#include <utility>
#include <algorithm>
using namespace std;


vector<string> topThree(string filename) {
    string line;
    ifstream infile (filename);//object for reading from a file
    vector<pair<string, int>> top_three(3);
    vector<string> ret;
    map<string, int> mymap;
    if (infile.is_open()) {
        while (getline(infile, line)) {
            if (mymap.count(line)) mymap[line]++;
            else  mymap.insert({ line, 0 });
        }
    }
    infile.close();

    partial_sort_copy(mymap.begin(),
                       mymap.end(),
                       top_three.begin(),
                       top_three.end(),
                       [](pair<const string, int> const& l,
                          pair<const string, int> const& r)
                       {
                           return l.second > r.second;
                       });
    for (int i = 0; i < 3; i++){
      ret.push_back(top_three[i].first);
    }
    return ret;
}
