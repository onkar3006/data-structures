#include "lib_util.h"
#include "lib_sort.h"

/* bubble sort */
void bubblesort (int a[], int length)
{
    int i,j;
    for (i=0; i<length; i++) {
        for (j=0; j<length-i-1; j++) {
            if (a[j]>a[j+1]) {
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

/* merge for mergesort */
static void merge(int a[], int left, int mid, int right)
{
    int n1 = mid-left+1;
    int n2 = right-mid;
    int a1[n1], a2[n2];
    int i, j, k;
    for(i=0; i<n1; i++)
        a1[i] = a[left+i];

    for(j=0; j<n2; j++)
        a2[j] = a[mid+j+1];

    i = 0;
    j = 0;
    k = left;
    while(i<n1 && j<n2) {
        if(a1[i]<a2[j])
            a[k++] = a1[i++];
        else
            a[k++] = a2[j++];
    }

    while(i<n1)
        a[k++] = a1[i++];

    while(j<n2)
        a[k++] = a2[j++];
}

/* merge sort */
void mergesort(int a[], int left, int right)
{
    int mid;
    if (left<right) {
        mid = left + (right-left)/2;

        mergesort(a, left, mid);
        mergesort(a, mid+1, right);
        merge(a, left, mid, right);
    }
}
