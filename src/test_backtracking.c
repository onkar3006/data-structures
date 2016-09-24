#include <stdio.h>
#include "test_backtracking.h"

void test_backtracking()
{
    /* Tower of Hanoi */
    int no_of_rings = 3;
    char from_peg   = 'A';
    char to_peg     = 'B';
    char aux_peg    = 'C';
    printf("\nTower Of Hanoi | Number of rings = %d", no_of_rings);
    tower_of_hanoi(from_peg, to_peg, aux_peg, no_of_rings);
}
