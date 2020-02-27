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

void reverselist(Node** head){
    Node* current=*head;
    Node* prev=nullptr;
    Node* next;
    while(current){
       next=current->next;
       current->next=prev;
       prev=current;
       current=next;
    }
    *head=prev;    
}

void reorderList(Node* head) 
{
    // Your code here
  //  Node* tempo=head;
    int count=0;
    
    Node* slow=head;
    Node* fast=slow->next;
    
    while(fast && fast->next){
      slow=slow->next;
      fast=fast->next->next;
       }
    
  
    Node* second=slow->next;
    slow->next=nullptr;
    Node* first=head;
    
    reverselist(&second);
    
    Node* head1=new Node(0);
    head=head1;
    
    while(first || second){
          
          if(first){
              head1->next=first;
              head1=head1->next;
              first=first->next;
          }
          if(second){
              head1->next=second;
              head1=head1->next;
              second=second->next;
          }  
    }
    
    head=head1->next;
  
}