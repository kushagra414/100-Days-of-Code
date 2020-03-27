// { Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */

void rearrange(struct Node *odd);

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        rearrange(start);
        printList(start);
    }
    return 0;
}
// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/

void rearrange(struct Node *odd)
{
    Node *temp = odd;
    int oddArray[1001], evenArray[1001];
    int countOdd = 0,i=0,countEven=0;
    while(temp){
        if(i%2 != 0)
            oddArray[countOdd++] = temp->data;
        else
            evenArray[countEven++] = temp->data;
        i++;
        temp=temp->next;
    }
    temp = odd;
    for(i=0;i<countEven and temp!=NULL;i++){
        temp->data = evenArray[i];
        temp=temp->next;
    }
    for(i=countOdd-1;i>=0 and temp!= NULL;i--){
        temp->data = oddArray[i];
        temp = temp->next;
    }
}