#include <stdio.h>
#include "../lib/lib_util.h"
#include "test_sorting.h"
#include "test_backtracking.h"

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

    return 0;
}
