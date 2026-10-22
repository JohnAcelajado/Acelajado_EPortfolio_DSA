#include <iostream>

// Recursive binary search function
int recursiveBinarySearch(int arr[], int left, int right, int key) {
    if (left > right) {
        // Base case: key not found
        return -1;
    }

    int mid = (left + right) / 2;
    std::cout << "Check index " << mid << " with value " << arr[mid] << std::endl;

    if (arr[mid] == key) {
        return mid;  // Found the key
    }
    else if (arr[mid] < key) {
        std::cout  << "Value is smaller than " << key << ", look right side" << std::endl;
        return recursiveBinarySearch(arr, mid + 1, right, key);  // Search right half
    }
    else {
        std::cout << "Value is bigger than " << key << ", look left side" << std::endl;
        return recursiveBinarySearch(arr, left, mid - 1, key);   // Search left half
    }
}

int main() {
    int sortedList[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = 10;
    int key = 8;

    std::cout << "Start recursive binary search for " << key << " in the list." << std::endl;

    int result = recursiveBinarySearch(sortedList, 0, size - 1, key);

    if (result != -1) {
        std::cout << "Found " << key << " at index " << result << "!" << std::endl;
    }
    else {
        std::cout << key << " is not in the list." << std::endl;
    }

    return 0;
}