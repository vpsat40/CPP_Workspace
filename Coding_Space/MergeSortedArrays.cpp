/*
Exercise #2.

Write a function that efficiently merges two already sorted arrays (allows duplicates) into a new sorted array

int* mergeSortedArray(int* array1, int numElements1, int* array2, int numElements2) {

// your code here

}

For example:

int a[4] = {1,4,6,8};
int b[6] = {3,5,5,6,9,10};

int* merged = mergeSortedArray(a, 4, b, 6);

// merged should contain {1,3,4,5,5,6,6,8,9,10}

*/

#include <stdio.h>
#include <stdlib.h>

int* mergeSortedArray(int* a, int num_a, int* b, int num_b)
{
    int idx_a = 0, idx_b = 0, idx =0;
    int* merged_Array = (int*)malloc((num_a + num_b)*sizeof(int));

    while((idx_a < num_a) && (idx_b < num_b))
    {
        if(a[idx_a] <= b[idx_b])
            merged_Array[idx++] = a[idx_a++];
        else
            merged_Array[idx++] = b[idx_b++];
    }

    while(idx_a < num_a)
        merged_Array[idx++] = a[idx_a++];
    
    while(idx_b < num_b)
        merged_Array[idx++] = b[idx_b++];

    return (&merged_Array[0]);
}

int main(void)
{
    int b[6] = {3,5,5,6,9,10};
    int a[4] = {1,4,6,8};

    int a_size = sizeof(a)/sizeof(a[0]);
    int b_size = sizeof(b)/sizeof(b[0]);

    printf("A Size - %d, B Size - %d\n", a_size, b_size);
    int* mergedArr = mergeSortedArray(a, a_size, b, b_size);

    for(int i= 0; i < (a_size+b_size); i++)
        printf("%d - \n", mergedArr[i]);
}
