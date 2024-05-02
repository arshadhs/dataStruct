/*
Selection sort is a simple and efficient sorting algorithm.
It repeatedly selects the smallest (or largest) element from the unsorted portion of the list and
moves it to the sorted portion of the list. 

Variation       Time Complexity     Space Complexity
Best Case       O(n2)               O(1)                (already sorted)
Average Case	O(n2)               O(1)                (random order, without a clear ascending or descending pattern)
Worst Case      O(n2)               O(1)                (descending)
*/

#include <iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int> & arr) {
    size_t s = arr.size();
    if (!s) return;     // empty vector !

    for (int i = 0; i < s-1; ++i) {
        int minIndex = i;

        for (int j = i+1; j < s; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if(minIndex != i) swap (arr[i], arr[minIndex]);
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

        selectionSort(testCase);

        cout << endl << "Sorted:   ";
        for(auto i : testCase)
            cout << " " << i;
    }

    return 0;
}