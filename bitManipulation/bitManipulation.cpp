#include<bitset>
#include<iostream>
using namespace std;

class BitManipulation {
    public:
        BitManipulation(const BitManipulation& ) = delete;
        BitManipulation operator =(const BitManipulation &) = delete;

        // Display in binary
        static void DisplayBits(int num) {
            while(num) {
                cout << (num & 1);
                num >>= 1;
            } 
        }

        // Displays with leading 0's
        template<typename T>
        static void DisplayBitSet(T num) {
            std::bitset<32> x(num);
            cout << x;
        }

        // set pos to 1
        static int SetBit(const int num, const int pos) {
            return num | (1 << pos);
        }

        // check if bit at pos is 1 - isSet
        static GetBit(const int num, const int pos) {
            return (num & (1 << pos) != 0);
        }

        // set bit at pos to 0
        static clearBit(const int num, const int pos) {
            int mask = ~(1 << num);
            return (num & mask);
        }

        // toggle bit at pos
        static int toggleBit(const int num, const int pos) {
            return (num ^ (1 << pos));
        }
};

int main() {
    int num = 5;
    int pos = 5;
    cout << endl << "Decimal: " << num << " Binary: "; BitManipulation::DisplayBitSet(num);
    num = BitManipulation::SetBit(num, pos);
    cout << endl << "Decimal: " << num << " Binary: "; BitManipulation::DisplayBitSet(num);
    bool set = BitManipulation::GetBit(num, 5);
    cout << endl << "Decimal: " << num << " Position: " << pos << " Set: " << set;
    num = BitManipulation::clearBit(num, 5);
    cout << endl << "Decimal: " << num << " Binary: "; BitManipulation::DisplayBitSet(num);
    num = BitManipulation::toggleBit(num, 0);
    cout << endl << "Decimal: " << num << " Binary: "; BitManipulation::DisplayBitSet(num);
    return 0;
}