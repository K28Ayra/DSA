#include <iostream>

using namespace std;

class Sorter {
public:
    static void selectionSort(int arr[], int size) {
        for (int i = 0; i < size - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            if (minIndex != i) {
                // Manual swap
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }
    }
};

int main() {
    // Input: Taking an array of integers from the user
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arrayToSort = new int[size];

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arrayToSort[i];
    }

    // Sorting using Selection Sort
    Sorter::selectionSort(arrayToSort, size);

    // Output: Displaying the sorted array
    cout << "Sorted array using Selection Sort: ";
    for (int i = 0; i < size; ++i) {
        cout << arrayToSort[i] << " ";
    }

    delete[] arrayToSort;  // Don't forget to free the allocated memory

    return 0;
}
