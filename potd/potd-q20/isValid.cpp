#include <string>
#include <stack>
#include <map>
using namespace std;

bool isValid(string input) {
  map<char, int> mp;
       mp['('] = -1;
       mp[')'] = 1;
       mp['{'] = -2;
       mp['}'] = 2;
       mp['['] = -3;
       mp[']'] = 3;

    stack<char> s;
    for (int i=0; i < int(input.size()); i++){
           if (mp[input[i]] < 0){
               s.push(mp[input[i]]);
           }else{
             if (!s.empty() && mp[input[i]]+s.top()==0){
               s.pop();
             }else{
               if (mp[input[i]]>0 ){
                 return false;
               }
             }

           }
      }
    if (!s.empty()){
      return false;
    }

    return true;    // modify this!
}
