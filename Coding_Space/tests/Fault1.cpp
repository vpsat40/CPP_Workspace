#include <iostream>

using namespace std;

const string& f()
// void f(string &s)
{
    return "abc";
    // s = "abc";
}

void g()
{
    // string s;
    string& s = f();
    // f(s);
    cout << s << endl;
}

int main(void)
{
    g();

    return 0;
}