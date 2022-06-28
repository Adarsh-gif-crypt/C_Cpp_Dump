#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

void add_at_end(struct node *head, int data)
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

void *add_at_beg(struct node **head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link = NULL;

    ptr->link = *head;
    *head = ptr;
}
void add_to_pos(struct node *head, int data, int pos)
{
    struct node *ptr = head;
    struct node *ptr1 = malloc(sizeof(struct node));
    ptr1->data = data;
    ptr1->link = NULL;

    pos--;
    while(pos!=1)
    {
        ptr = ptr->link;
        pos--;
    }
    ptr1->link=ptr->link;
    ptr->link=ptr1;
}


int main(){

struct node *head = malloc(sizeof(struct node));
printf("Enter 1 to add at beginning\n");
printf("Enter 2 to add at the end\n");
printf("Enter 3 to add at a certain position");
int val;
int data;
scanf("%d",&val);
if(val==1){
    printf("Enter Data to be added: ");
    scanf("%d",&data);
    add_at_beg(head,data);
}
else if(val==2){
    printf("Enter Data to be added: ");
    scanf("%d",&data);
    add_at_end(head, data);
}
else if(val == 3){
    int pos;
    printf("Enter Data to be added: ");
    scanf("%d",&data);
    printf("Position of the addition: ");
    scanf("%d",&pos);
    add_to_pos(head,data,pos);
}
else{
    printf("Select Valid option!");
}
return 0;

}
