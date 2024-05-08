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

        // Displays with leading 0's - uses bitset
        template<typename T>
        static void DisplayBitSet(T num) {
            std::bitset<32> x(num);
            cout << x;
        }

        // set (bit at) pos to 1
        // left-shift the value 1 by pos positions (1<< pos) and perform a bitwise OR operation with num
        static int SetBit(const int num, const int pos) {
            return num | (1 << pos);
        }

        // check if bit at pos is 1 - isSet
        // bitwise AND operation with a mask having only that bit set.
        // If the result is non-zero, the bit is set; otherwise, it’s unset.
        static GetBit(const int num, const int pos) {
            return (num & (1 << pos) != 0);
        }

        // set (bit at) pos to 0
        // Left-shift the value 1 by pos positions (1<< pos) 
        // then use bitwise NOT operator ‘~’ to unset this shifted 1 making the bit at position pos to 0 
        // then use Bitwise AND with num that will unset bit at desired positon of num.
        static clearBit(const int num, const int pos) {
            int mask = ~(1 << num);
            return (num & mask);
        }

        // toggle bit at pos
        // Use the bitwise XOR (^) operator to toggle (flip) the bit at the given position.
        // If the bit is 0, it becomes 1, and if it’s 1, it becomes 0.
        static int toggleBit(const int num, const int pos) {
            return (num ^ (1 << pos));
        }

        // Check Odd
        static bool isOdd(const int num) {
            return (num & 1);
        }

        // Properties for numbers which are powers of 2, is that they have one and only one bit set in their binary representation.
        // If the number is neither zero nor a power of two, it will have 1 in more than one place.
        // So if x is a power of 2 then x & (x-1) will be 0.
        static bool isPowerOfTwo(const int num) {
            return (num && !(num & (num - 1)));
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

    num = 5;
    bool isPowerOf2 = BitManipulation::isPowerOfTwo(num);
    cout << endl << "Decimal: " << num << " isPowerOf2: " << isPowerOf2;
    cout << endl << "Decimal: " << num << " isOdd: " << BitManipulation::isOdd(num);

    num = 8;
    isPowerOf2 = BitManipulation::isPowerOfTwo(num);
    cout << endl << "Decimal: " << num << " isPowerOf2: " << isPowerOf2;
    cout << endl << "Decimal: " << num << " isOdd: " << BitManipulation::isOdd(num);

    return 0;
}