#include <iostream>

using namespace std;

int main(void)
{
    // int i = 0;

    // while(i++ <= 100)
    for(int i = 1; i <= 100; i++)
    {
        if((i%3 == 0) && (i%5 == 0))
            cout << "AncaCnc" << endl;
        else if (i%3 == 0)
            cout << "Anca" << endl;
        else if (i%5 == 0)
            cout << "Cnc" << endl;
        else
            cout << i << endl;
    }

    return 0;
}