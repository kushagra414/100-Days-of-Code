// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}

Node* constructTree(int n, int pre[], char preLN[]);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed

int Index=0;
Node *root=NULL;

Node *BuildTree(struct Node *root,int pre[], char preLN[], int N){
    if(Index == N)
        return NULL;
    struct Node *node = (Node *)malloc(sizeof(struct Node));
    node->data = pre[Index]; node->left = NULL; node->right = NULL;
    if(root==NULL)
        root = node;
    if(preLN[Index++]=='L')
        return node;
    node->left = BuildTree(root,pre,preLN,N);
    node->right = BuildTree(root,pre,preLN,N);
    return node;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    Node *root=NULL;
    Index = 0;
    root = BuildTree(root,pre,preLN,n);
    return root;
}