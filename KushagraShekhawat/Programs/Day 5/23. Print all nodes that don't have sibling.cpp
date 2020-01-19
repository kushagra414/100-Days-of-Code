// { Driver Code Starts
//Initial Template for C++

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


/* Computes the number of nodes in a tree. */
void printSibling(Node *);

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
   printSibling(root);
   cout<<endl;
  }
  return 0;
}

// } Driver Code Ends
//User function Template for C++

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/* Prints the nodes having no siblings.  */

int height(Node* root){
    if(root == NULL)
        return 0;
    else{
        int lheight = height(root->left);
        int rheight = height(root->right);

        if(lheight>rheight)
            return ++lheight;
        return ++rheight;
    }
}


int PrintNodesWithNoSibling(Node *node,int h,int have_siblings, int hash[]){
    if(node == NULL){
        // DO nothing
    }
    else if(h==1 && have_siblings == 0){
        hash[node->data] = 1;
    }
    else if(h>1){
        int have_siblings = 1;
        if(node->left != NULL && node->right == NULL)
            have_siblings = 0;
        else if(node->left == NULL && node->right != NULL)
            have_siblings = 0;
        PrintNodesWithNoSibling(node->left,h-1,have_siblings,hash);
        PrintNodesWithNoSibling(node->right,h-1,have_siblings,hash);
    }
}

void printSibling(Node* node)
{
    int h = height(node);
    int hash[1000],all_nodes_had_siblings=1;
    for(int i=0;i<1000;i++)
        hash[i] = 0;
    for(int i=0;i<h;i++){
        PrintNodesWithNoSibling(node, i+1, 1,hash);
   }
    for(int i=0;i<1000;i++){
        if(hash[i]==1){
             printf("%d ",i);
             all_nodes_had_siblings = 0;
        }
    }
    if(all_nodes_had_siblings)
         printf("-1");
}
   