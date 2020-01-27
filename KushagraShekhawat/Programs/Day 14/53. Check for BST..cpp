// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
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

/* Returns true if the given tree is a binary search tree
 (efficient version). */
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
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

     cout << isBST(root) << endl;
  }
  return 0;
}
// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
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

int BSTarray[101],i=0;

void checkBST(Node *root){
    if(root==NULL)
        return;

    checkBST(root->left);
    BSTarray[i++]=root->data;
    //printf("Data :%d \n",BSTarray[i-1]);
    checkBST(root->right);
}

bool isSorted(int arr[]){
    int sorted=1;
    for(int j=0;j<i;j++){
        for(int k=0;k<i-j-1;k++){
            //printf("k: %d, k+1: %d,\n",arr[k],arr[k+1]);
            if(arr[k]>arr[k+1]){
               // printf("True");
                return 0;
            }
        }
        return 1;
    }
    return 1;
}

bool isBST(Node* root) {
    for(int j=0;j<101;j++)
        BSTarray[j]=0;
    i=0;
    checkBST(root);
    return isSorted(BSTarray);
}
