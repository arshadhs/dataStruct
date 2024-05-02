/*
 Insertion Sort works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list.
 It is a stable sorting algorithm, meaning that elements with equal values maintain their relative order in the sorted output.
 
 “in-place” sorting algorithm, meaning it doesn’t require any additional memory space beyond the original array.

Variation       Time Complexity     Space Complexity
Best Case       O(n)                O(1)                (already sorted)
Average Case	O(n^2)              O(1)
Worst Case      O(n^2)              O(1)                (descending)

*/

#include <iostream>
#include<vector>

using namespace std;

template <typename T>
void insertionSort(vector<T> & arr) {
    size_t n = arr.size();
    if (!n) return;

    // begin sorting from the second element of the array (loop variable i = 1)


    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;

        // Move elements of arr [0..i-1], that are greater than key, to 1 position ahead of their current position

        // iteratively compare the current element (key) to all the previous elements.
        // (key < arr[j] for ascending, and key < arr[j] for descending).
        while(key < arr[j] && j >= 0) {
            arr[j + 1] = arr [j];
            --j;
        }

        // The key is then placed in its correct position based on the order specified
        arr[j + 1] = key;
    }
}

int main() {
    vector<vector<int>> testCases =     {
        {64, 34, 25, 12, 22, 11, 90},
        {9, 8, 7, 6, 5, 4, 3, 2, 1},
        {3, 1, 4, 1, 5, 9, 2, 6, 5},
        {2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 7, 4, 5},
        {0},
        {}
    };

    for (auto & testCase :  testCases) {
        cout << endl << "Unsorted: ";
        for(auto i : testCase)
            cout << " " << i;

        insertionSort(testCase);

        cout << endl << "Sorted:   ";
        for(auto i : testCase)
            cout << " " << i;
    }

    return 0;
}