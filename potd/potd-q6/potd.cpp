// your code here!
#include <iostream>
#include "math.h"
#include "potd.h"

int *potd::raise(int *arr) {
    int size = 1;
    for (int i = 0; arr[i] != -1; i++) {
        size = size + 1;
    }
    std::cout << size << std::endl;
    int *arr_new = new int[size];
    for (int j = 0; j < size - 2; j++) {
        arr_new[j] = pow(arr[j], arr[j + 1]);
    }
    arr_new[size - 2] = arr[size - 2];
    arr_new[size - 1] = -1;
    return arr_new;
    delete[] arr_new;
}
