#include <stdio.h>
#include "../lib/lib_util.h"
#include "test_sorting.h"
#include "test_backtracking.h"
#include "test_linklist.h"

int main(int argc, char *argv[])
{

    /* test sorting algorithms */
    printf("\n############### SORTING ###############");
    test_sorting();
    printf("---------------------------------------\n");

    /* test backtracking algorithms */
    printf("\n############ BACKTRACKING #############");
    test_backtracking();
    printf("\n---------------------------------------\n");


    /* test link list algorithms */
    printf("\n############# LINK LIST ###############");
    test_linklist();
    printf("\n---------------------------------------\n");


    return 0;
}
