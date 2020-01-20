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

Node* insert(Node* node, int data) 
{
    
    if(node == NULL) return(new Node(data)); 
    else
    {
        if (data <= node->data)node->left = insert(node->left, data);
        else node->right = insert(node->right, data);
        return node; 
    }
}

int minValue(Node* root);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, tmp;
        cin>>n>>tmp;
        Node* root = NULL;
        root = insert(root, tmp);
        n--;
        while(n--){
            cin>>tmp;
            insert(root, tmp);
        }
        cout<<minValue(root)<<endl;
    }
    return 0;
}
// } Driver Code Ends
/*
Structure of the node of the binary search tree is as
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

// your task is to complete the below function


int minimumVal(Node *root, int minimum_val){
    if(root == NULL){
        return minimum_val;
    }
    else{
        if(minimum_val>root->data)
            minimum_val = root->data;
        minimum_val = minimumVal(root->left, minimum_val);
        minimum_val = minimumVal(root->right, minimum_val);
        return minimum_val;
    }
}

int minValue(Node* root)
{
    return minimumVal(root, 101);
}