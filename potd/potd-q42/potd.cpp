#include <unordered_map>

using namespace std;

//check if a string is in a map
bool check_key(unordered_map<string, int> map,string s){
  if (map.find(s) == map.end()) return false;
  return true;
}
unordered_map<string, int> common_elems(unordered_map<string, int> &mapA,
                                        unordered_map<string, int> &mapB) {

    // your code here
    unordered_map<string, int> mapC;
    //iterate every element in mapA, check if it exists in mapB
    for (auto it = mapA.begin(); it != mapA.end(); it++){
      string target = it->first;
      if (check_key(mapB,target)){
        mapC.insert({target,it->second+mapB[target]});
      }
    }
    for (auto it = mapB.begin(); it != mapB.end();){
      string target = it->first;
      if (check_key(mapC,target)){
        //it++;
        it = mapB.erase(it);
      }
      else it++;
    }
    for (auto it = mapA.begin(); it != mapA.end();){
      string target = it->first;
      if (check_key(mapC,target)){
        //it++;
        it = mapA.erase(it);
      }
      else it++;
    }
    return mapC;
}
