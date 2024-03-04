#include <iostream>
#include <vector>

// Merge two sorted subarrays into one sorted array
void merge(std::vector<int>& arr, int left, int middle, int right) {
    // Calculate the sizes of the two subarrays to be merged
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays for the two subarrays
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[middle + 1 + j];

    // Merge the two subarrays back into the original array
    int i = 0; // Index for the left subarray
    int j = 0; // Index for the right subarray
    int k = left; // Index for the merged array

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Main function to perform merge sort on the array
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Calculate the middle index to divide the array into two halves
        int middle =  (right + left) / 2;

        // Recursively sort the first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Merge the sorted halves
        merge(arr, left, middle, right);
    }
}

int main() {
    // Example usage
    std::vector<int> arr = {1232, 2311, 133, 523, 6, 7};

    // Display the original array
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Perform merge sort
    mergeSort(arr, 0, arr.size() - 1);

    // Display the sorted array
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
