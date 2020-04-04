// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void append(Node** head_ref, Node **tail_ref, int new_data)
{
    Node* newnode = new Node(new_data);
    
    if(*head_ref == NULL)
        *head_ref = newnode;
    else
        (*tail_ref)->next = newnode;
    *tail_ref = newnode;
}

Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K;
        cin>>num>>K;
        int temp;
        Node* head = NULL;
        Node* tail = NULL;
        for(int i = 0; i<num; i++){
            cin>>temp;
            append(&head, &tail, temp);
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends
//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

// Should swap Kth node from beginning and Kth
// node from end in list and return new head.
Node *swapkthnode(Node* head, int num, int K)
{
    if(K>num)
        return head;
    int Kend = num-K+1,count=0;
    Node *root=head,*prev1=NULL,*prev2=NULL,*swap1,*swap2;
    Node *next1=NULL,*next2=NULL,*previous=NULL;
    while(root){
        count++;
        if(count==K){
            swap1 = root;
            next1 = root->next;
            prev1=previous;
        }
        if(count==Kend){
            swap2 = root;
            next2 = root->next;
            prev2=previous;
        }
        previous = root;
        root=root->next;
    }
    
    if(prev1)
        prev1->next=swap2;
    else
        head = swap2;
    if(prev2)
        prev2->next=swap1;
    else
        head = swap1;
    Node *temp=swap1->next;
    swap1->next=swap2->next;
    swap2->next=temp;
    return head;
}
