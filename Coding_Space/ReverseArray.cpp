/*
 * Exercise #1.
 In your text file write a function that reverses an array of ints:
void reverse(int* array, int numElements) {
// your code here
}

Example input:
int a[6] = {3,6,8,1,4,6}
reverse(a, 6);
// should result in {6,4,1,8,6,3}

*/
#include <stdio.h>

void reverse(int *a, int numElements)
{
    if (numElements < 2)
        return;
    
    for(int i = 0; i < numElements/2; i++)
    {
        a[i] = a[i] + a[numElements-1 - i];
        a[numElements-1 - i] = a[i] - a[numElements-1 - i];
        a[i] = a[i] - a[numElements-1 -i];
    }    
}
int main(void)
{
    int a[6] = {3, 6, 1, 4, 6, 2};
    int arr_size = sizeof(a)/sizeof(a[0]);

    reverse(a, arr_size);

    for(int i= 0; i < arr_size; i++)
        printf("%d - \n", a[i]);
}