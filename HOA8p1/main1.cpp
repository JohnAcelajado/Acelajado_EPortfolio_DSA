#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sort.h"

const int maxSize = 10;

void displayArr(int arr[]);

int main() {
    int unsortedArr[maxSize];

    std::srand(std::time(0));

    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = std::rand() % 100;
    }

    std::cout << "Original Array:\n";
    displayArr(unsortedArr);

    int pivot = partition(unsortedArr, 0, maxSize - 1);

    std::cout << "\nAfter Partition:\n";
    displayArr(unsortedArr);

    shellSort(unsortedArr, pivot);
    shellSort(unsortedArr + pivot + 1, maxSize - pivot - 1);

    std::cout << "\nAfter Sorting Left and Right Sublists:\n";
    displayArr(unsortedArr);

    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}