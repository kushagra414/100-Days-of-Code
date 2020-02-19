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


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        *tree = new Node(val);
        return;
    }
    if(val < (*tree)->data)
    { insert(&(*tree)->left, val);}
    else if(val > (*tree)->data)
    { insert(&(*tree)->right, val);}
}
void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node * deleteNode(Node *root,  int );

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
            insert(&root, k);}
        int r;
        cin>>r;
        root = deleteNode(root,r);
        inorder(root);
        cout<<endl;
    }
}// } Driver Code Ends

/* The structure of a BST Node is as follows:
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
*/

Node *findmin(Node *root){
    Node *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node *deleteNode(Node *root,  int x)
{
    if(root==NULL){
        return root;
    }
    else if(x>root->data){
        root->right=deleteNode(root->right,x);
    }
    else if(x<root->data){
        root->left=deleteNode(root->left,x);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            struct Node *temp=root;
            root=NULL;
            delete temp;
            return root;
        }
        else if(root->left==NULL){
            struct Node *temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        else if(root->right==NULL){
            struct Node *temp=root;
            root=root->left;
            delete temp;
            return root;
        }
        else{
            struct Node *temp=findmin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
            return root;
        }
    }
}
