/*
Merge sort is a sorting algorithm that follows the divide-and-conquer approach.
It works by recursively dividing the input array into smaller subarrays and sorting those subarrays then merging them back together
to obtain the sorted array.

1. Divide:  Divide the list or array recursively into two halves until it can no more be divided.
2. Conquer: Each subarray is sorted individually using the merge sort algorithm.
3. Merge:   The sorted subarrays are merged back together in sorted order.
            The process continues until all elements from both subarrays have been merged.

Variation       Time Complexity     Space Complexity
Best Case       O(n log n)          
Average Case	O(n log n)          
Worst Case      O(n log n)          
*/
#include <iostream>
#include<vector>
using namespace std;

/// 1. Declare left variable to 0 and right variable to n-1 
/// 2. Find mid by medium formula. mid = (left+right)/2
/// 3. Call merge sort on (left,mid)
/// 4. Call merge sort on (mid+1,right)
/// 5. Continue till left is less than right
/// 6. Then call merge function to perform merge sort.

template<typename T>
void merge(vector<T>& arr, int left, int mid, int right) {
    // TBD
}

template<typename T>
void mergeSort(vector<T> & arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge (arr, left, mid, right);
    }
}

template<typename T>
void mergeSort(vector<T>& arr) {
    int n = arr.size();
    if (!n) return;

    mergeSort(arr, 0, n - 1);
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

        mergeSort(testCase);

        cout << endl << "Sorted:   ";
        for(auto i : testCase)
            cout << " " << i;
    }

    return 0;
}
