#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_Node = new Node(new_data);

    new_Node->next = (*head_ref);
    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}
int detectloop(struct Node *list);
/* Driver program to test above function*/
int main() {
    int t, n, c, x, i;
    cin >> t;
    while (t--) {
        /* Start with the empty list */
        cin >> n;
        struct Node *head = NULL;
        struct Node *temp;
        struct Node *s;
        cin >> x;
        push(&head, x);
        s = head;
        for (i = 1; i < n; i++) {
            cin >> x;
            push(&head, x);
        }
        /* Create a loop for testing */
        cin >> c;
        if (c > 0) {
            c = c - 1;
            temp = head;
            while (c--) temp = temp->next;
            s->next = temp;
        }
        int g = detectloop(head);
        if (g)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends

/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
int detectloop(Node *head) 
{
	int f=0,x=0;
	Node *temp = head ; 
    while( temp != NULL )
    {	
    	Node *temp1 = head; int x1=0;
    	while( x1<x )
    	{
    		if( temp1 == temp )
    		{  
    			return 1;
			}
			temp1=temp1->next;
			x1++;
		}
		temp = temp->next;
		x++;
	}
	return 0;
}

