// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
	
	node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printList(struct node *node)
{
    while(node!=NULL){
        cout<<node->data<<' ';
        node = node->next;
    }
    printf("\n");
}

void push(struct node** head_ref, int new_data)
{
    struct node* new_node =	new node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

struct node* makeUnion(struct node* head1, struct node* head2);

int main()
{
    long test;
    cin>>test;
    while(test--)
    {
        struct node* a = NULL;
        struct node* b = NULL;
        int n, m, tmp;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>tmp;
            push(&b, tmp);
        }
        printList(makeUnion(a, b));
    }
    return 0;
}
// } Driver Code Ends
/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
	
	node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/
struct node* makeUnion(struct node* head1, struct node* head2)
{
    node *prev,*prev2,*h1=head1,*h2=head2;
    map<int,int>ump;
    while(h1){
        if(!ump[h1->data])
            ump[h1->data]=1;
        prev=h1;
        h1=h1->next;
    }
    prev->next=h2;
    while(h2){
        if(!ump[h2->data])
            ump[h2->data]=1;
        h2=h2->next;
    }
    h1=head1;
    for(auto it=ump.begin();it!=ump.end();++it){
        h1->data=it->first;
        prev=h1;
        h1=h1->next;
    }
    prev->next=NULL;
    return head1;
}
