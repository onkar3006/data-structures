#include <stdio.h>
#include <stdlib.h>
#include "lib_linklist.h"

LLNode * create_node(int data)
{
    LLNode *new_node = malloc(sizeof(LLNode));
    if (new_node == NULL) {
        printf("\nmalloc failure\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void linklist_append(LLNode **head, int data)
{
    LLNode *new_node = create_node(data);
    if (new_node == NULL) {
        printf("\nFailed to create a new node.\n");
        return;
    }

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    LLNode *curr_node = *head;
    while(curr_node->next)
        curr_node = curr_node->next;

    curr_node->next = new_node;
}

void linklist_remove(LLNode **head)
{
    if (*head == NULL) {
        printf("\nEmpty Linklist\n");
        return;
    }

    LLNode *curr_node = *head;
    LLNode *prev_node = NULL;

    if (curr_node->next == NULL) {
        free(curr_node);
        *head = NULL;
        return;
    }

    while(curr_node->next) {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    prev_node->next = NULL;
    free(curr_node);
}

int linklist_length(LLNode *head)
{
    LLNode *current_node = head;
    int length = 0;
    while(current_node) {
        length++;
        current_node = current_node->next;
    }
    return length;
}

void linklist_print(LLNode *head)
{
    if (head == NULL) {
        printf("\nEmpty Linklist.\n");
        return;
    }

    LLNode *curr_node = head;
    while(curr_node) {
        printf("%d ", curr_node->data);
        curr_node = curr_node->next;
    }
}

int linklist_find_nth_node_from_end(LLNode *head, int n)
{
    if(head == NULL) {
        printf("\nEmpty Linklist.\n");
        return -1;
    }

    LLNode *first_ptr  = head;
    LLNode *second_ptr = head;
    int count = 0;
    while(first_ptr && count<n) {
        first_ptr = first_ptr->next;
        count++;
    }

    if (first_ptr == NULL) {
        printf("\n%dth node does not exist\n", n);
        return -1;
    }

    while(first_ptr) {
        second_ptr = second_ptr->next;
        first_ptr = first_ptr->next;
    }

    return second_ptr->data;
}

void linklist_loop_create(LLNode *head, int pos)
{
    if(head == NULL) {
        printf("\nEmpty Linklist.\n");
        return;
    }

    LLNode *first_ptr  = head;
    LLNode *second_ptr = head;
    int count = 0;
    while(first_ptr && count<pos) {
        first_ptr = first_ptr->next;
        count++;
    }

    if (first_ptr == NULL) {
        printf("\n%dth node does not exist\n", pos);
        return;
    }

    while(second_ptr->next) { 
        second_ptr = second_ptr->next;
    }

    second_ptr->next = first_ptr;
}

int linklist_loop_exists(LLNode *head)
{
    if(head == NULL) {
        printf("\nEmpty Linklist.\n");
        return 0;
    }

    LLNode *fast_ptr = head;
    LLNode *slow_ptr = head;
    
    while(fast_ptr->next && fast_ptr->next->next) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
        if (fast_ptr == slow_ptr)
            return 1;
    }
    return 0;
}

int linklist_loop_length(LLNode *head)
{
    int length = 0;
    if(linklist_loop_exists(head)) {
        LLNode *fast_ptr = head;
        LLNode *slow_ptr = head;

        while(fast_ptr->next && fast_ptr->next->next) {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            if(slow_ptr == fast_ptr)
                break;
        }

        do {
            length++;
            slow_ptr = slow_ptr->next;
        } while(slow_ptr != fast_ptr);
    }
    return length;
}
