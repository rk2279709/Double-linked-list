#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*next;
    struct node*previous;
}*newnode,*head,*tem;
int node_count=0;

// add node at last
void add()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&(newnode->data));
    newnode->next=0;
    newnode->previous=0;
    if (head==0)
    {
        head=newnode;
        temp=newnode;
        node_count++;
    }
    else
    {
        temp->next=newnode;
        newnode->previous=temp;
        temp=newnode;
        node_count++;
    }
    printf("\n\n");
    return;
}
// display node
void display()
{
    struct node*display=head;
    if (head==0)
    {
        printf("List is empty\n\n");
    }
    else
    {
        printf("\nYour Node is: ");
        while(display!=0)
        {
            printf("%d->",display->data);
            display=display->next;
        }
        printf("\n\n");

    }
    printf("\n\n");
    return;
}
// number of nodes printing
void number_of_node()
{
    printf("The number of nodes till now is: %d\n",node_count);
    printf("\n\n");
    return;
}
// delete a node
void del()
{
    int flag=1;
    if(head==0)
    {
        printf("List is empty\n\n");
        return;
    }
    int index;
    printf("enter a node index to delete a node, remember node index starts from 0: ");
    scanf("%d",&index);
    struct node*t=head;
    if(index==0)
    {
        head=head->next;
        free(t);
        node_count--;
    }
    else if(index==(node_count-1))
    {
        t=temp;
        temp=temp->previous;
        temp->next=0;
        free(t);
        node_count--;
    }
    else if(index>0 && index<node_count)
    {
        while (index!=0)
        {
            t=t->next;
            index-=1;
        }
        t->next->previous=t->previous;
        t->previous->next=t->next;
        free(t);
        node_count--;
    }
    else
    {
        printf("Index out of range\n\n");
        return;
    }
    printf("node deleted\n\n");
    return;
}
// insert at middle
void mid()
{
    int index;
    printf("enter index number after which you want to insert node: ");
    scanf("%d",&index);
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&(newnode->data));
    newnode->next=0;
    newnode->previous=0;
    struct node*t2=head;
    while(index!=0)
    {
        t2=t2->next;
        index-=1;
    }
    newnode->previous=t2;
    newnode->next=t2->next;
    t2->next=newnode;
    newnode->next->previous=newnode;
    printf("\n\n");
    node_count++;
    return;

}
int main()
{
    int choice;
    while (choice!=0)
    {
        printf("Enter your choice:\n Press 1 to add node at last\n Press 2 display node\n Press 3 to delete a node\n Press 4 to insert node at middle\n Press 8 to display number of nodes\n Press 9 to clear screen\n Press 0 to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:
                break;
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                del();
                break;
            case 4:
                mid();
                break;
            case 8:
                number_of_node();
                break;
            case 9:
                system("cls");
                break;
        }
    }
}
