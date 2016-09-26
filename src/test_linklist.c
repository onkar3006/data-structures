#include <stdio.h>
#include "test_linklist.h"

void test_linklist()
{
    LLNode *head = NULL;

    printf("\nLinklist (length=%d) | ", linklist_length(head));
    linklist_print(head);

    head = create_node(1);

    printf("\nLinklist (length=%d) | ", linklist_length(head));
    linklist_print(head);

    linklist_remove(&head);

    printf("\nLinklist (length=%d) | ", linklist_length(head));
    linklist_print(head);

    linklist_append(&head, 1);
    linklist_append(&head, 2);
    linklist_append(&head, 3);
    linklist_append(&head, 4);
    linklist_append(&head, 5);
    linklist_append(&head, 6);
    linklist_append(&head, 7);
    linklist_append(&head, 8);
    linklist_append(&head, 9);
    linklist_append(&head, 10);
    linklist_append(&head, 11);
    linklist_append(&head, 12);

    printf("\nLinklist (length=%d) | ", linklist_length(head));
    linklist_print(head);

    printf("\n\nRemove 2 nodes from the end.\n");
    linklist_remove(&head);
    linklist_remove(&head);

    printf("\nLinklist (length=%d) | ", linklist_length(head));
    linklist_print(head);

    int n = 5;
    printf("\n\n%dth node from end: %d", n, linklist_find_nth_node_from_end(head, n));

    printf("\n\nLoop exists ? %s\n", (linklist_loop_exists(head))?"Yes":"No");

    printf("\nCreate loop at position %d", n);
    linklist_loop_create(head, n);
    printf("\n\nLoop exists ? %s", (linklist_loop_exists(head))?"Yes":"No");

    printf("\n\nLoop length = %d", linklist_loop_length(head));

    printf("\n\nRemove the loop");
    linklist_loop_remove(head);
    printf("\n\nLoop exists ? %s", (linklist_loop_exists(head))?"Yes":"No");
    printf("\n\nLinklist (length=%d) | ", linklist_length(head));
    linklist_print(head);

    printf("\n\nMergesort on linklist:");
    linklist_mergesort(&head);
    printf("\nLinklist (length=%d) | ", linklist_length(head));
    linklist_print(head);

    printf("\n\nReversing the linklist");
    linklist_reverse(&head);
    printf("\nLinklist (length=%d) | ", linklist_length(head));
    linklist_print(head);

    printf("\n\nMergesort on linklist:");
    linklist_mergesort(&head);
    printf("\nLinklist (length=%d) | ", linklist_length(head));
    linklist_print(head);

    DLLNode *head_dll = linklist_to_doubly_linklist(head);
    printf("\n\nDoubly Linklist (length=%d) | ", linklist_length_dll(head_dll));
    linklist_print_dll(head_dll);


}
