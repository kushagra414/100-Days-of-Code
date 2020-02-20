// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


Node *compute(Node *head);

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Node *result = compute(head);
        print(result);
        cout<<endl;
    }
}
// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node *compute(Node *root)
{
    Node *head = root;
    stack<int>s;
    s.push(head->data);
    head=head->next;
    while(head){
        int data = head->data;
        while(!s.empty() and s.top()<data){
            s.pop();
        }
        s.push(data);
        head=head->next;
    }
    Node *last = new Node(s.top());
    s.pop();
    while(!s.empty()){
        Node *newnode = new Node(s.top());
        newnode->next = last;
        s.pop();
        last = newnode;
    }
    return last;
}

