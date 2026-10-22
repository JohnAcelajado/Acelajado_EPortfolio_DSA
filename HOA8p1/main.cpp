#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sort.h"

const int maxSize = 100;

void displayArr(int arr[]);

int main() {
    int unsortedArr[maxSize];

    std::srand(std::time(0));

    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = std::rand() % 100;
    }

    std::cout << "Unsorted Array:\n";
    displayArr(unsortedArr);

    std::cout << "\nShell Sort:\n";
    shellSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    std::cout << "\nMerge Sort:\n";
    mergeSort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr);

    std::cout << "\nQuick Sort:\n";
    quickSort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr);

    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}