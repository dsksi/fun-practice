//Implement link list in C
//Store input from stdin to a linked list structure
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
struct _node {
    int value;
    struct _node *next;
};

struct _list {
    node *head;
    int nitems;
};

//helper functions:
node *newNode(int n);
 
//creates an empty new list
list *newlist(void) {
    list *new = malloc(sizeof(list));
    new->head = NULL;
    new->nitems = 0;
    return new;
}

//add value to list to the start of node
void push(int n, list *l) {
    node *first = l->head;
    node *new = newNode(n);
    new->next = l->head;
    l->head = new;
    l->nitems++;
}

void addValueEnd(int n, list *l) {
    node *tmp = l->head;
    node *new = newNode(n);
    if (tmp == NULL) {
        l->head = new;
        l->nitems++;
    }
    //traverse to find last element in list
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
    l->nitems++;
}

//find the index of the value
int findN(list *l, int n) {
    //empty list
    if (l->nitems == 0) {
        return -1;
    }
    node *tmp = l->head;
    int counter = 0;
    while (tmp != NULL && tmp->value != n) {
        tmp = tmp->next;
        counter++;
    }
    if (tmp == NULL) {
        return -1;
    } else {
        return counter;
    }
}

void printList(list *l) {
    if(l->head == NULL) {
        return;
    }

    node *tmp = l->head;
    printf("List: ");
    while(tmp!= NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

//delete the first element(pop)
int pop(list *l) {
    if(l->head == NULL) {
        return -1;
    }
    node *tmp = l->head;
    l->head = l->head->next;
    return tmp->value;
}
//Helper functions:
node *newNode(int n) {
    node *new = malloc(sizeof(node));
    new->value = n;
    new->next = NULL;
    return new;
}

