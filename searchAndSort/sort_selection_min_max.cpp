/*
Selection sort: Get the MAX also on every pass and place it at its correct position.
So in every pass, we keep track of both MAX and MIN and array becomes sorted from both ends.

Time Complexity: O(n*n)
Auxiliary space: O(1)
*/

/// TBD: doesn't work for few test cases, fix it !

#include <iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int> & arr) {
    size_t s = arr.size();
    if (!s) return;     // empty vector !

    for (int i = 0; i < s/2 + 1; ++i) {
        int minIndex = i;
        int maxIndex = i;

        for (int j = i+1; j < s-i; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
            else if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }

        if(minIndex != i) swap (arr[i], arr[minIndex]);
        if(maxIndex != s - i - 1) swap (arr[s - i - 1], arr[minIndex]);

        std::cout << "\nAfter iteration " << i+1 << ": ";
        for (int k = 0; k < arr.size(); ++k) {
            std::cout << arr[k] << " ";
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

        selectionSort(testCase);

        cout << endl << "Sorted:   ";
        for(auto i : testCase)
            cout << " " << i;
    }

    return 0;
}