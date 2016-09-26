#ifndef LIB_LINKLIST_H_
#define LIB_LINKLIST_H_

typedef struct node {
    int data;
    struct node * next;
} LLNode;

typedef struct node_dll {
    int data;
    struct node_dll *next;
    struct node_dll *prev;
} DLLNode;

LLNode * create_node(int data);
DLLNode * create_node_dll(int data);

void linklist_append(LLNode **head, int data);

void linklist_remove(LLNode **head);

int linklist_length(LLNode *head);
int linklist_length_dll(DLLNode *head);

void linklist_print(LLNode *head);
void linklist_print_dll(DLLNode *head);

int linklist_find_nth_node_from_end(LLNode *head, int n);

int linklist_loop_exists(LLNode *head);

void linklist_loop_create(LLNode *head, int pos);

void linklist_loop_remove(LLNode *head);

int linklist_loop_length(LLNode *head);

void linklist_front_bak_split(LLNode *head, LLNode **front_ref, LLNode **back_ref);

LLNode * linklist_sorted_merge(LLNode *a, LLNode *b);

void linklist_mergesort(LLNode **head_ref);

void linklist_reverse(LLNode **head_ref);

DLLNode * linklist_to_doubly_linklist(LLNode *head);

#endif // LIB_LINKLIST_H_
