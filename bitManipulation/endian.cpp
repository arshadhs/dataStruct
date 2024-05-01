#include<iostream>
using namespace std;

class Solution {
public:
    // function to show bytes in memory, from location start to start+n 
    void showEndian(char *c, size_t s) {

        for (int i = 0; i < s; i++) {
            printf(" %u", &c[i]);
        }


        for (int i = 0; i < s; i++) {
            printf(" %.2x", c[i]);
        }
        printf("\n");
    }

    // determining endianness of your machine
    void checkIndian() {
        int i = 1;
        showEndian((char *)&i, sizeof(i));
        char *c = (char *)&i;
        if (*c) cout << "\nLittle endian";
        else cout << "\nBig endian";
    }
};

int main () {
    Solution s;
    int i = 0x01234567;
    s.showEndian((char *)&i, sizeof(i));

    s.checkIndian();
    return 0;
}