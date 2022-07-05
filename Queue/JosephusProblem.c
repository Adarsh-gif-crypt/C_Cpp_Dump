//This is a manual implementation of Josephus Problem without using the formula
/*Josephus Problem is a problem in Computer Science in which there are a number of people(n) in a circle waiting to be eliminated. 
In every turn, the kth(k) number gets eliminated. The last man standing is the winner. The task is to find the winner. 
The current formulated solution is in the link https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//Declaring Linked List node
struct node
{
    int player_no;
    struct node *next;
};
struct node *start,*ptr,*new_node;

//main function
int main()
{
    int n,k,count;
    printf("Number of Players: ");
    scanf("%d",&n);
    printf("Value of k: ");
    scanf("%d",&k);

    start = malloc(sizeof(struct node));
    ptr = start;
    
    for(int i=2;i<=n;i++)
    {
        new_node = malloc(sizeof(struct node));
        ptr->next = new_node;
        new_node->player_no = i;
        new_node->next=start;
        ptr = new_node;
    }
    for(count = n;count>1;count--)
    {
        for(int i = 0;i < k-1;++i)
        {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;
        //removing eliminated player from the linked list
    }
    printf("\nThe winner is Player %d",ptr->player_no);
    getche();

    return 0;
}