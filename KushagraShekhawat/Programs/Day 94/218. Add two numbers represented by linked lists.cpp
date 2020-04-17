// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* addTwoLists(struct Node* first, struct Node* second);

void push(struct Node** head_ref, int new_data) {
    struct Node* new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
void freeList(struct Node* Node) {
    struct Node* temp;
    while (Node != NULL) {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* res = NULL;
        struct Node* first = NULL;
        struct Node* second = NULL;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first) freeList(first);
        if (second) freeList(second);
    }
    return 0;
}
// } Driver Code Ends
/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// write a function returns the resultant linked list
Node* addTwoLists(Node* f, Node* s) {
    Node *head,*temp,*prev,*first=f,*second=s;
    bool FirstorSec=0;
    int carry=0,sum=0,arr[102]={-1},size=0,add,i;
    while(first and second){
        sum=first->data+second->data+carry;
        arr[size++] = sum%10;
        sum/=10;
        carry=sum;
        first=first->next;
        second=second->next;
    }
    while(first){
        sum=first->data+carry;
        arr[size++] = sum%10;
        sum/=10;
        carry=sum;
        FirstorSec=0;
        first=first->next;
    }
    while(second){
        sum=second->data+carry;
        arr[size++] = sum%10;
        sum/=10;
        carry=sum;
        FirstorSec=1;
        second=second->next;
    }
    if(carry){
        arr[size++]=carry;
    }
    if(FirstorSec){
        head = s;
        temp=head;
    }
    else{
        head = f;
        temp=head;
    }
    for(i=0;i<size and temp;i++){
        temp->data = arr[i];
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL and i<size){
        Node *next = new Node(arr[i]);
        prev->next=next;
    }
    return head;
}