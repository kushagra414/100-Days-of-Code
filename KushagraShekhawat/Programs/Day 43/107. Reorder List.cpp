// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head) ;

/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node *head)
{
	struct Node* temp;
    while(head != NULL)
    {
        
        temp=head;
        head = head->next;
        free(temp);
    }
  
}

int main(void)
{
   int t,n,m,i,x;
   
   cin>>t;
   while(t--)
   {
	   struct Node* temp,*head;
	    cin>>n;
	    cin>>x;
	    head=new Node(x);
	    temp=head;
	    for(i=0;i<n-1;i++)
	    {
			cin>>x;
			temp->next=new Node(x);
			temp=temp->next;
			}
	   
		reorderList(head);
	    printList(head);
        freeList(head);
   }
   return 0;
}
// } Driver Code Ends
/* Following is the Linked list node structure */


/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

void reorderList(Node* head) 
{
    Node *node = head,*previous=NULL,*first=NULL,*last=NULL;
    int size=0;
    while(node){
        node=node->next;
        size++;
    }
    Node *arr[size];
    node=head;
    int i=0,j=0;
    while(node){
        arr[i++]=node;
        node=node->next;
    }
    for(i=0,j=size-1;i<=j;i++,j--){
        first = arr[i];
        last = arr[j];
        first->next = last;
        if(previous)
            previous->next=first;
        previous = last;
    }
    previous->next = NULL;
}

