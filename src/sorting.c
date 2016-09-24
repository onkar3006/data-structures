#include <stdio.h>
#include "../lib/libutil.h"
#include "../lib/libsort.h"

int main(int argc, char *argv[])
{
    int array[10] = {10,9,8,7,6,5,4,3,2,1};
    int length    = sizeof(array) / sizeof(int);

    printf("\nOriginal array : ");
    print_array(array, length);

    /* bubble sort */
    bubblesort(array, length);
    printf("\nBubble sort    : ");
    print_array(array, length);
    printf("\n");

    /* reverse back to original array */
    reverse_array(array, length);
    printf("\nOriginal array : ");
    print_array(array, length);

    /* merge sort */
    mergesort(array, 0, length-1);
    printf("\nMerge sort     : ");
    print_array(array, length);
    printf("\n");

    return 0;
}
