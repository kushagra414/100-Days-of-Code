// { Driver Code Starts
#include<iostream>
#include<stdio.h>
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

int intersectPoint(struct Node* head1, struct Node* head2);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends
/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    int l1=0,l2=0,f=0;
    Node *temp=head1 , *temp1=head2 ,*temp2;
    while( temp!=NULL )
    {
        l1++;
        temp = temp->next;
    }
    while( temp1!=NULL )
    {
        l2++;
        temp1 = temp1->next;
    }
    temp =head1 ; temp1 = head2;
    if(l1<l2)
    {
        int temp0 =l1;  temp2=temp;
        l1=l2;  temp=temp1;
        l2=temp0;   temp1=temp2;
    }
    while(l1!=0 && l2!=0)
    {
        if(l1!=l2)
        {
            temp = temp->next; l1--;
        }
        else
        {
            if(temp->data==temp1->data)
            {
                f=1;break;
            }
            else
            {
                temp=temp->next;
                temp1=temp1->next;
                l1--;l2--;
            }
        }
    }
    if(f==1)
    return temp->data;
    else
    return -1;
}

////////can be done very easily using stack;


