#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief This template takes in function "f" and executes it for all integers in vector
 * 
 * @tparam func 
 * @param fn - function "fn" that will be defined in future
 * @param arr - a vector of integers that be defined in future
 */
template <typename func>
void filter(func fn, vector<int> arr)
{
    for(auto i : arr)
    {
        if(fn(i))
            cout << i << " ";
    }
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};

    // We are calling template filter function fn
    // The first parameter fn is a lambda function that returns true if x > 3
    // The second parameter is vector
    filter([](int x) { cout << " " ; return (x > 3);}, vec);
    cout << endl;

    filter([](int x) { cout << " "; return (x > 2 && x <7);}, vec);
    cout << endl;

    // Following is an example of variable capture using lambda function
    // [&] captures variable y

    int y = 6;
    filter([&](int x) {return (x > y);}, vec);
}