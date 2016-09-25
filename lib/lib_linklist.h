#ifndef LIB_LINKLIST_H_
#define LIB_LINKLIST_H_

typedef struct node {
    int data;
    struct node * next;
} LLNode;

LLNode * create_node(int data);

void linklist_append(LLNode **head, int data);

void linklist_remove(LLNode **head);

int linklist_length(LLNode *head);

void linklist_print(LLNode *head);

int linklist_find_nth_node_from_end(LLNode *head, int n);

int linklist_loop_exists(LLNode *head);

void linklist_loop_create(LLNode *head, int pos);

int linklist_loop_length(LLNode *head);
#endif // LIB_LINKLIST_H_
