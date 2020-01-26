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

bool isSumTree(struct Node* node);

/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

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

     cout << isSumTree(root) << endl;
  }
  return 0;
}// } Driver Code Ends
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
int SumTree=1;
int findSumTree(Node *root){
    //printf("SumTree :%d\n",SumTree);
    int leftsum=0,rootVal=0,rightsum=0;
    if(SumTree==0){
        return 0;}
    if(root==NULL)
        return 0;
    rootVal=root->data;
    leftsum+=findSumTree(root->left);
    rightsum+=findSumTree(root->right);
    //Leafsum+=root->data;}
    if(leftsum+rightsum!=rootVal)
        SumTree=0;
    if(leftsum==rightsum&&leftsum==0)
        SumTree=1;
    //printf("SumTree :%d, total :%d\n",SumTree,leftsum+rightsum);
    return leftsum+rightsum+rootVal;
}

bool isSumTree(Node* root)
{
    SumTree=1;
     findSumTree(root);
     if(SumTree)
        return 1;
     return 0;
}
