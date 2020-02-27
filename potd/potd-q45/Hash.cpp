#include <vector>
#include <iostream>
#include "Hash.h"
size_t count = 0;
size_t length = 0;
void doubleHashInput(std::vector<int> &v, int elem){
	//your code here
  count++;
  if (length == 0) length = v.size();
  else{
    if (shouldResize(count,length)){
      size_t newlength = findPrime(2*length);
      Resize_vector(v,newlength);
  }
  }
  int index1 = firstHash(elem,length);
  int index2 = secondHash(elem);
  while (v[index1] != -1){
    index1 = index1+index2;
  }
  v[index1] = elem;
}

//make a hash function called firstHash
//make a second function called secondHash
// 5,27 -> 20   5*4 % 27 =20
// 20,5 -> 20*4 %5 =0
int firstHash(int elem, int length){
   std::cout <<(elem*4)%length<< std::endl;
    return (elem*4)%length;
}
int secondHash(int elem){
    return 3-(elem%3);
}

const size_t primes[]
    = {17ul,         29ul,         37ul,        53ul,        67ul,
       79ul,         97ul,         131ul,       193ul,       257ul,
       389ul,        521ul,        769ul,       1031ul,      1543ul,
       2053ul,       3079ul,       6151ul,      12289ul,     24593ul,
       49157ul,      98317ul,      196613ul,    393241ul,    786433ul,
       1572869ul,    3145739ul,    6291469ul,   12582917ul,  25165843ul,
       50331653ul,   100663319ul,  201326611ul, 402653189ul, 805306457ul,
       1610612741ul, 3221225473ul, 4294967291ul};


size_t findPrime(size_t num)
{
    size_t len = sizeof(primes) / sizeof(size_t);
    const size_t* first = primes;
    const size_t* last = primes + len;
    const size_t* prime = std::upper_bound(first, last, num);
    if (prime == last)
        --prime;
    return *prime;
}

bool shouldResize(size_t count, size_t length)
    {
        return static_cast<double>(count) / length >= 0.7;
    }

void Resize_vector(std::vector<int> &v, size_t newlength){{

}
