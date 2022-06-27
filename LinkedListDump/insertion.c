#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void insert_at_end(struct node *head, int data)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = malloc(sizeof(struct node));

    temp->data=data;
    temp->link=NULL;

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link = temp;
}

struct node *add_at_beg(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link = NULL;

    ptr->link = head;
    head = ptr;
    return head;
}
