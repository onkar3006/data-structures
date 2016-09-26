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
DLLNode * create_node_dll(int data)
{
    DLLNode *new_node = malloc(sizeof(DLLNode));
    if (new_node == NULL) {
        printf("\nmalloc failure\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
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

int linklist_length_dll(DLLNode *head)
{
    DLLNode *current_node = head;
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

void linklist_print_dll(DLLNode *head)
{
    if (head == NULL) {
        printf("\nEmpty Doubly Linklist.\n");
        return;
    }

    DLLNode *curr_node = head;
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
    int count = 1;
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

    printf("\nLoop created at node %d", first_ptr->data);
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

void linklist_loop_remove(LLNode *head)
{
    if (!linklist_loop_exists(head)) {
        printf("\nLoop doesn't exist.");
        return;
    }

    LLNode *slow_ptr = head;
    LLNode *fast_ptr = head;

    do {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

    } while(slow_ptr != fast_ptr);

    slow_ptr = head;

    while(fast_ptr->next != slow_ptr->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }

    fast_ptr->next = NULL;
    printf("\nLoop removed at node %d", slow_ptr->next->data);
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

void linklist_front_back_split(LLNode *head, LLNode **front_ref, LLNode **back_ref)
{
    if(head == NULL || head->next == NULL) {
        *front_ref = head;
        *back_ref  = NULL;
        return;
    }

    LLNode *fast_ptr = head;
    LLNode *slow_ptr = head;

    while(fast_ptr->next && fast_ptr->next->next) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    *front_ref = head;
    *back_ref  = slow_ptr->next;
    slow_ptr->next = NULL;
}

LLNode* linklist_sorted_merge(LLNode *a, LLNode *b)
{
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    LLNode *result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = linklist_sorted_merge(a->next, b);
    }
    else {
        result = b;
        result->next = linklist_sorted_merge(a, b->next);
    }

    return result;
}

void linklist_mergesort(LLNode **head_ref)
{
    LLNode *head = *head_ref;
    if(head == NULL || head->next == NULL)
        return;

    LLNode *a;
    LLNode *b;

    linklist_front_back_split(head, &a, &b);

    linklist_mergesort(&a);
    linklist_mergesort(&b);

    *head_ref = linklist_sorted_merge(a, b);
}

void linklist_reverse(LLNode **head_ref)
{
    LLNode *curr_node = *head_ref;
    if (curr_node == NULL || curr_node->next == NULL)
        return;

    LLNode *next_node = NULL;
    LLNode *prev_node = NULL;

    while(curr_node) {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }

    *head_ref = prev_node;
}

DLLNode * linklist_to_doubly_linklist(LLNode *head)
{
    if(head == NULL)
        return NULL;

    DLLNode *curr_node_dll = create_node_dll(head->data);
    if(curr_node_dll == NULL) {
        printf("\nCannot create doubly linklist node.");
        return NULL;
    }
    curr_node_dll->next = linklist_to_doubly_linklist(head->next);

    return curr_node_dll;
}

