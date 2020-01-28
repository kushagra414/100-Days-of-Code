// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node* insert(Node* node, int data);
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            root = insert(root, k);
        }
        inorder(root);
        cout<<endl;
}
}
// } Driver Code Ends
/* The structure of a BST node is as follows:
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; */

/* This function should insert a new node with 
  given data and return root of the modified tree  */
  
Node *insert_node(Node *root, int data){
    if(root == NULL){
        Node *node =  (Node *)malloc(sizeof(Node));
        node->data = data;
        return node;
    }
    else if(root->data>data){
            Node *new_node = insert(root->left,data);
            root->left = new_node;
    }
    else if(root->data<data){
            Node *new_node = insert(root->right,data);
            root->right = new_node;
    }
}
  
Node* insert(Node* root, int data)
{
    if(root == NULL)
        root = insert_node(root,data);
    else
        insert_node(root,data);
    return root;
}