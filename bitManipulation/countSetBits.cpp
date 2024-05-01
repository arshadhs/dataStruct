#include<iostream>
using namespace std;

void showBits(int num) {
    while(num)
    {
        cout << (num & 1);
        num >>=1;
    }
}

void showBits_1(int num) {
    for (int i = (sizeof(num)*8) -1 ; i >= 0; i--)
    {
        cout << (num & (1 << i) ? 1 : 0);
    }
}

int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;        
    }
    return count;
}

// Brian Kernighan’s Algorithm
int countSetBits_1(int num) {
    int count = 0;
    while (num) {
        num = num & (num-1);
        count++;
    }
    return count;
}

int main()
{
    int i = 544;
    showBits(i); cout << endl;
    showBits_1(i);
    cout << endl <<  countSetBits(i);
    cout << endl <<  countSetBits_1(i);
}