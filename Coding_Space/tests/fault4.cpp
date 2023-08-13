#include <iostream>
#include <string.h>

using namespace std;

class MString
{
    public:
        const MString& operator = (const MString& rhs);

    private:
        char* cptr;
};

const MString& MString::operator=(const MString& rhs)
{
    // Clear old value
    if((cptr) && (cptr != rhs.cptr))
        delete cptr;

    //Copy new value from the rsh
    int len = strlen(rhs.cptr);
    cptr = new char[len +1];
    strcpy(cptr, rhs.cptr);

    return *this;
}

int main()
{
    MString a;
    a = a;

    return 0;
}

