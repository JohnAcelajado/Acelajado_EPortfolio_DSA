#ifndef SORTINGSUPPLEMENT_H
#define SORTINGSUPPLEMENT_H

#include <iostream>

// Insertion Sort
template <typename T>
void insertionSort(T arr[], int arrSize) {
    int k = 1, j;
    T temp;

    while (k < arrSize) {
        temp = arr[k];
        j = k - 1;

        // Added 'j >= 0' to prevent out-of-bounds array access (arr[-1])
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;   // responsible for swapping
        }
        arr[j + 1] = temp; // responsible for swapping
        k++; // responsible for swapping
    }
}

#endif