/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order.
This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high.

In Bubble Sort algorithm, 
1. traverse from left and compare adjacent elements and the higher one is placed at right side. 
2. In this way, the largest element is moved to the rightmost end at first. 
3. This process is then continued to find the second largest and place it and so on until the data is sorted.

Variation       Time Complexity     Space Complexity
Best Case       O(n)                O(1)                (already sorted)
Average Case	O(n^2)              O(1)
Worst Case      O(n^2)              O(1)                (descending)
*/

#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &arr) {
    size_t s = arr.size();
    if (!s) return;     // empty vector !

    bool swapped = false;

    for(int i = 0; i < s - 1; ++i) {
        for(int j = 0; j < s - i - 1; ++j) {
            if (arr[j] > arr[j+1]) {    // Swap if needed
                swap(arr[j], arr[j+1]); 
                swapped = true;
            }

            if (!swapped) {
                break; // If no two elements were swapped in the inner loop, then the array is already sorted 
            }
        }
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

        bubbleSort(testCase);

        cout << endl << "Sorted:   ";
        for(auto i : testCase)
            cout << " " << i;
    }

    return 0;
}