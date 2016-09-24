#include <stdio.h>
#include "libutil.h"

/* print utility */
void print_array(int a[], int length)
{
    int i;
    for (i=0; i<length; i++) {
        printf("%d ", a[i]);
    }
}


/* swap utility */
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a   = *b;
    *b   = temp;
}

/* reverse array */
void reverse_array(int a[], int length)
{
    int i = 0;
    int j = length-1;

    while(i<j) {
        swap(&a[i], &a[j]);
        i++;
        j--;
    }
}
