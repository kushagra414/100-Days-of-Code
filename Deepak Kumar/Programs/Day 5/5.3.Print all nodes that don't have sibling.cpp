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
int flag=0;
stack <int >s;

void sibling(Node* node){
    if(node==NULL){
        return;
    }
    if(node->left!=NULL && node->right!=NULL){
        sibling(node->left);
        sibling(node->right);
    }
    if(node->left!=NULL && node->right==NULL){
        s.push(node->left->data);
        sibling(node->left);
    }
    if(node->left==NULL && node->right!=NULL){
        s.push(node->right->data);
        sibling(node->right);
    }
    int n=s.size();
    int i=0,j=0;
    int arr[n];
    for(i=0;i<n;i++){
        arr[i]=s.top();
        s.pop();
    }
    for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]<arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
        flag=1;
    }
}

void printSibling(Node* node){
    flag=0;
    sibling(node);
    if(flag==0)
        printf("-1");
}
