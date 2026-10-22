#include <iostream>

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        std::cout << "Check index " << mid << " with value " << arr[mid] << std::endl;

        if (arr[mid] == key) {
            return mid;  
        }
        else if (arr[mid] < key) {
            std::cout << "Value is smaller than " << key << ", look right side" << std::endl;
            left = mid + 1;
        }
        else {
            std::cout << "Value is bigger than " << key << ", look left side" << std::endl;
            right = mid - 1;
        }
    }

    return -1;  
}

int main() {
    int sortedList[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = 10;
    int key = 8;

    std::cout << "Start searching for " << key << " in the list." << std::endl;

    int result = binarySearch(sortedList, size, key);

    if (result != -1) {
        std::cout << "Found " << key << " at index " << result << "!" << std::endl;
    }
    else {
        std::cout << key << " is not in the list." << std::endl;
    }

    return 0;
}