// { Driver Code Starts
// C program to find the mirror Node in Binary tree
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

/* A binary tree Node has data, pointer to left child
and a pointer to right child */
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int counter=0;
int target=0;
struct Node *ptr=NULL;
// create new Node and initialize it

// recursive function to find mirror of Node
int findMirrorRec(int target, struct Node* left,
							struct Node* right);

// interface for mirror search
int findMirror(struct Node* root, int target)
{
	if (root == NULL)
		return 0;
	if (root->key == target)
		return target;
	return findMirrorRec(target, root->left, root->right);
}
 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
 /*void Inorder(struct Node* root)
{

    if(counter==0)
    {
        cin>>target;
        counter++;
    }

    if(root==NULL)
        return ;

    Inorder(root->left);

    if(root->key==target)
         ptr=root;

    Inorder(root->right);
}*/
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>target;
    counter=0;
    int mirror = findMirror(root, target);

	if (mirror)
		printf("%d\n",mirror);
	else
		printf("-1\n");
    }
    return 0;
}// } Driver Code Ends
// recursive function to find mirror of Node
int findMirrorRec(int target, struct Node* left,
							struct Node* right)
{
    if(!left or !right)
        return -1;
        
    if(left->key==target)
        return right->key;
    if(right->key==target)
        return left->key;
    
    int mirrorVal = findMirrorRec(target, left->left, right->right);
    if(mirrorVal>0)
        return mirrorVal;
    findMirrorRec(target,left->right,right->left);
}