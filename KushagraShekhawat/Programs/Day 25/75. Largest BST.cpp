// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
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

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int largestBst(Node *root);

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

    cout<<largestBst(root)<< endl;
  }
  return 0;
}


// } Driver Code Ends
/* Tree node structure  used in the program
 struct Node
 {
     int data;
     struct Node* left, *right;
};*/

/*You are required to complete this method */

#define BSTSubTree(root,infoLeft,infoRight) (root->data>infoLeft.maxVal)&&(root->data<infoRight.minVal)

struct BSTInfo{
    bool isBST;
    int maxBST;
    int minVal;
    int maxVal;
};

BSTInfo IsBST(BSTInfo infoLeft,BSTInfo infoRight){return {true,infoLeft.maxBST+infoRight.maxBST+1,infoLeft.minVal,infoRight.maxVal};}
BSTInfo NotBST(BSTInfo infoLeft,BSTInfo infoRight){return {false, max(infoLeft.maxBST,infoRight.maxBST),0,0};}

struct BSTInfo LongestBST(Node *root){
    if(root==NULL)
	    return {true,0,1001,0};
	if(!root->right&&!root->left)
	    return {true,1,root->data,root->data};

	BSTInfo infoLeft = LongestBST(root->left);
	BSTInfo infoRight = LongestBST(root->right);

	if(infoLeft.isBST&&infoRight.isBST)
	    return BSTSubTree(root,infoLeft,infoRight)?IsBST(infoLeft,infoRight):NotBST(infoLeft,infoRight);
	else
	    return NotBST(infoLeft,infoRight);
}

int largestBst(Node *root)
{
    BSTInfo info = LongestBST(root);
    return info.maxBST;
}

