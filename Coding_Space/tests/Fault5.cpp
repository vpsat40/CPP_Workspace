#include <iostream>
#include <string.h>

using namespace std;

class MString
{
    public:
        MString(const char* initCptr = "");
        ~MString();

    private:
        char* cptr;
};

MString::MString(const char* initCptr): cptr(new char[strlen(initCptr) +1])
{
    strcpy(cptr, initCptr);
}

MString::~MString()
{
    if(cptr != nullptr)
    {
        cout << "Delete called" << endl;
        free(cptr);
        cptr = nullptr;
    }
    else
        cout << "Cptr already destroyed" << endl;
}

void function_fn()
{
    MString str1("Hello");
    // MString str2 = str1;
}

int main()
{
    function_fn();

    return 0;
}