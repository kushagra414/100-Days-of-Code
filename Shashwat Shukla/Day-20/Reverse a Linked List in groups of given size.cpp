// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse (struct node *head, int k);

struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* UTILITY FUNCTIONS */
/* Function to push a node */

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

     int t;
     cin>>t;
     
     while(t--)
     {
         struct node* head = NULL;
         struct node* temp = NULL;
         int n;
         cin >> n;
         
         for(int i = 0;i<n;i++){
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
         }
        
        int k;
        cin>>k;
        head = reverse(head, k);

        printList(head);
    
     }
     
     return(0);

}

// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

struct node *reverse (struct node *head, int k)
{ 
    int i=0; struct node *temp1=head ,*temp=head; 
    stack<int> st;
    while(temp!=NULL)
    {
    	if(i<k)
    	{
    		st.push(temp->data);
    		temp=temp->next; i++;
		}
		else
		{
			while(i>0)
			{
				head->data=st.top();
				st.pop(); i--;
				head = head->next;
			}
		}
	}
	while(!st.empty())
	{
		head->data=st.top();
		st.pop();
		head = head->next;
	}
	return temp1;
}

