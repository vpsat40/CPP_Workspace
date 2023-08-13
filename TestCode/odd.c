#define CUSTOM_MACRO(x, y) x##y

main(){

  int xValue = 20;
  printf(“%d”, CUSTOM_MACRO(x, Value));    //Prints 20

}