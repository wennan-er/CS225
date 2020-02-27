#include <iostream>
#include "potd.cpp"

using namespace std;

int main() {
    unordered_map<string, int> mapA({
                                    {"common", 13},
                                    {"common2", 57},
                                    {"unique_a", 13},
                                    {"unique_a2", 44},
                                    });
    unordered_map<string, int> mapB({
                                    {"common", 17},
                                    {"common2", 32},
                                    {"unique_b", 17},
                                    {"unique_b2", 78},
                                    });

    unordered_map<string, int> common = common_elems(mapA, mapB);

    // check your outputs here
    /*
    for (auto i = common.begin(); i != common.end(); i++)
        cout << i->first << "      " << i->second
             << endl;
             */
    cout << "element in mapA" << endl;
    for (auto i = mapA.begin(); i != mapA.end(); i++)
        cout << i->first << "      " << i->second
            << endl;
    cout << "element in mapB" << endl;
    for (auto i = mapB.begin(); i != mapB.end(); i++)
        cout << i->first << "      " << i->second
            << endl;
    return 0;
}
