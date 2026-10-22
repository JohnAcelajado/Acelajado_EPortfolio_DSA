#ifndef SORT_H
#define SORT_H

void shellSort(int arr[], int size){
    for (int gap = size/2; gap>= 1; gap = gap/2){
        for (int i = gap; i<size; i++){
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp){
                arr[j] = arr[j-gap];
                j = j - gap;
            }

            arr[j] = temp;
        }
    }
}

void merge(int arr[], int left, int middle, int right){
    int n1 = middle - left+1;
    int n2 = right - middle;

    int leftArr[n1];
    int rightArr[n2];

    for (int i = 0; i<n1; i++){
        leftArr[i] = arr[left + i];
    }

    for (int i = 0; i<n2; i++){
        rightArr[i] = arr[middle + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i<n1 && j<n2){
        if (leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j<n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
    if (left<right){
        int middle = (left + right) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j<high; j++){
        if (arr[j] < pivot){
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high){
    if (low<high){
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

#endif