#include <iostream>
using namespace std;

#define CUSTOM_MACRO(x, y) x##y
// Concatenation
//  Check https://www.ibm.com/docs/en/zos/2.3.0?topic=mdd-operator

main()
{

  int Value = 20;
  cout << CUSTOM_MACRO(x, Value) << endl;    //Prints 20

}