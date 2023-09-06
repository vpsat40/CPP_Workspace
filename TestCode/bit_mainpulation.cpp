#include <iostream>
#include <bitset>

using namespace std;

#define BIT_TST(nr, m) ((nr) & (m))     // nr - number, m - mask    Test/Check a bit - AND with mask
#define BIT_SET(nr, m) ((nr) |= (m))    // nr - number, m - mask    Set a bit - OR with mask 
#define BIT_CLR(nr, m) ((nr) &= ~(m))   // nr - number, m - mask    Clear a bit - AND with complement of mask
#define BIT_INV(nr, m) ((nr) ^= (m))    // nr - number, m - mask    Invert or toggle - XOR with mask


int main(void)
{
    // ---------------// 0b 8765 4321
    // ---------------// || |||| ||||
    uint8_t a = 0x3B; // 0b 0011 1011
    uint8_t b = 0x96; // 0b 1001 0110
    uint8_t c;

    c = a & b;
    cout << "a   =    0b-" << bitset<8>(a) << endl;
    cout << "b   =    0b-" << bitset<8>(b) << endl;
    cout << "c(a&b) = 0b-" << bitset<8>(c) << endl;
    cout << "-----------------------" << endl;

    c = a | b;
    cout << "a   =    0b-" << bitset<8>(a) << endl;
    cout << "b   =    0b-" << bitset<8>(b) << endl;
    cout << "c(a|b) = 0b-" << bitset<8>(c) << endl;
    cout << "-----------------------" << endl;


    c = a ^ b;
    cout << "a   =    0b-" << bitset<8>(a) << endl;
    cout << "b   =    0b-" << bitset<8>(b) << endl;
    cout << "c(a^b) = 0b-" << bitset<8>(c) << endl;
    cout << "-----------------------" << endl;

    c = ~a ;
    cout << "a   =    0b-" << bitset<8>(a) << endl;
    cout << "c( ~a) = 0b-" << bitset<8>(c) << endl;
    cout << "-----------------------" << endl;

    c = a ^ b;
    cout << "a   =    0b-" << bitset<8>(a) << endl;
    cout << "b   =    0b-" << bitset<8>(b) << endl;
    cout << "c(a^b) = 0b-" << bitset<8>(c) << endl;
    cout << "-----------------------" << endl;

    BIT_SET(a, (1 << 2));
    cout << "Setting bit 2 - a = 0b-" << bitset<8>(a) << endl;
    cout << "-----------------------" << endl;

    b = b | (1 << 3);
    cout << "Setting bit 3 - b = 0b-" << bitset<8>(b) << endl;
    cout << "-----------------------" << endl;

    BIT_CLR(a, (1 << 2));
    cout << "Clearing bit 2 - a = 0b-" << bitset<8>(a) << endl;
    cout << "-----------------------" << endl;

    b = b & ~(1 << 3);
    cout << "Clearing bit 3 - b = 0b-" << bitset<8>(b) << endl;
    cout << "-----------------------" << endl;

    BIT_INV(a, 0xff);
    cout << "Inverting all bits of - a = 0b-" << bitset<8>(a) << endl;
    cout << "-----------------------" << endl;

    b = b ^ 0xff;
    cout << "Inverting all bits of - b = 0b-" << bitset<8>(b) << endl;
    cout << "-----------------------" << endl;

}