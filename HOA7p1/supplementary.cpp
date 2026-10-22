#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "sortingSupplement.h"

// Generate an array A[0…100] of unsorted elements
// the values is range to its 1 to 5

const int maxSize = 101;

void displayArr(int arr[]);

int main() {
    // create an array with unsorted list 
    int unsortedArr[maxSize];

    std::string candidates[5] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustín",
        "Deja Jayla Bañaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    // use time(0) as seed for random values
    std::srand(std::time(0));

    // populate the array with random values ranging from 1 to 5
    for (int i = 0; i < maxSize; i++) {
        unsortedArr[i] = (std::rand() % 5) + 1;
    }

    std::cout << "Unsorted Array:\n";
    displayArr(unsortedArr);

    std::cout << "\nInsertion Sort:\n";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    // Vote counting algorithm
    int voteCounts[5] = {0};
    for (int i = 0; i < maxSize; i++) {
        voteCounts[unsortedArr[i] - 1]++;
    }

    std::cout << "\n--- Count Result of Algorithm ---\n";
    int maxVotes = -1;
    int winningIndex = -1;

    for (int i = 0; i < 5; i++) {
        std::cout << "Candidate " << (i + 1) << " [" << candidates[i] << "] ----- " 
                  << voteCounts[i] << " votes\n";

        if (voteCounts[i] > maxVotes) {
            maxVotes = voteCounts[i];
            winningIndex = i;
        }
    }

    std::cout << "\nWinner: Candidate " << (winningIndex + 1) << " [" 
              << candidates[winningIndex] << "] with " << maxVotes << " votes!\n";

    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}