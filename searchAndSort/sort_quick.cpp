/* 
Quick Sort algorithm is a Divide and Conquer algorithm.
It initially selects an element as a pivot element and partitions the given array around the picked pivot.
There are many different versions of quickSort that pick pivot in different ways. 
1. Always pick the first element as a pivot (implemented below).
2. Always pick the last element as the pivot.
3. Pick a random element as a pivot.
4. Pick median as a pivot.

The key process in quickSort is the partition() process. 
The aim of the partition() function is to receive an array and an element x of the array as a pivot, 
put x at its correct position in a sorted array and then put all smaller elements (smaller than x) before x,
and put all greater elements (greater than x) after x. All this should be done in linear time i.e.  Big O(n) .

Partition is done recursively on each side of the pivot after the pivot is placed in its correct position and this finally sorts the array.

Variation       Time Complexity     Space Complexity
Best Case       O(n log n)          O(log n)
Average Case	O(n log n)          O(log n)
Worst Case      O(n^2)              O(n)
*/
#include <iostream>
#include<vector>
using namespace std;

template<typename T>
int partition(vector<T>& arr, int start, int end) {
    T pivot = arr[end];
    int k = start - 1;

    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            k++;
            swap(arr[i], arr[k]);
        }
    }
    swap(arr[k + 1], arr[end]);
    return k + 1;
}

template<typename T>
void quickSort(vector<T>& arr, int start, int end) {
    if (start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

template<typename T>
void quickSort(vector<T>& arr) {
    int n = arr.size();
    if(!n) return;

    quickSort(arr, 0, n - 1);
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

        quickSort(testCase);

        cout << endl << "Sorted:   ";
        for(auto i : testCase)
            cout << " " << i;
    }

    return 0;
}