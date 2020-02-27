#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Hash.h"

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	for (int i = 0; i < (int) str.length(); ++i)
	{
		b_hash = b_hash * 33 + str[i];
	}
	return b_hash % M;
}

float hash_goodness(std::string str, int M)
{
    //std::vector<int>* array = new std::vector<int>(M,0);	// Hint: This comes in handy
		std::vector<int> array;
		array.resize(M);
	int permutation_count = 0;
	float goodness = 0;
	int num_of_collisions = 0;
	do {
		if (permutation_count == M) break;
		// Code for computing the hash and updating the array
		int index = int(bernstein(str,M));
 	 if (array[index]==0) {array[index] = 1;}
 	 else{num_of_collisions++;

 	 }
 	 permutation_count++;
	} while(std::next_permutation(str.begin(), str.end()));

	goodness = num_of_collisions*1.0/permutation_count;

	//Code for determining goodness

	return goodness;
}
