#include <stdio.h>
#include "lib_util.h"
#include "lib_backtracking.h"

/* tower of hanoi */
void tower_of_hanoi(char from_peg, char to_peg, char aux_peg, int no_of_rings)
{
    /* if only 1 ring, move it to dest peg and return */
    if(no_of_rings == 1) {
        printf("\nMove ring %d from peg %c to peg %c", no_of_rings, from_peg, to_peg);
        return;
    }

    /* move (n-1) rings from A to C using B as auxilary */
    tower_of_hanoi(from_peg, aux_peg, to_peg, no_of_rings-1);

    /* move remaining rings from A to B */
    printf("\nMove ring %d from peg %c to peg %c", no_of_rings, from_peg, to_peg);

    /* move (n-1) rings from C to B using A as auxilary */
    tower_of_hanoi(aux_peg, to_peg, from_peg, no_of_rings-1);
}
