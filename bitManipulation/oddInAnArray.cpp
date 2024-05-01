// program to find odd occcuring elements in an array

// The bitwise XOR operator is the most useful operator from a technical interview perspective.
// It is used in many problems. A simple example could be “Given a set of numbers where all elements occur an even number of times except one number, 
// find the odd occurring number” This problem can be efficiently solved by doing XOR to all numbers. 

// https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/

#include<iostream>
#include <vector>

using namespace std;

int findOff(vector <int> v) {
    int odd = 0;
    for(int i : v)
        odd  ^= i;
    return odd;
}

int main()
{
    vector<int> v = { 12, 12, 14, 90, 14, 14, 14 };
    cout << endl << "Odd one out: " << findOff(v);

    return 0;
}
