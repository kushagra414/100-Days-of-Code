// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// A wrapper over leftViewUtil()
void leftView(struct Node *root);


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

     leftView(root);
     cout << endl;
  }
  return 0;
}
// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// A wrapper over leftViewUtil()
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


int PrintLeftView(Node *root,int h,int lflag){
    if(root == NULL){
        return 0;
    }
    if(h==1 && lflag == 0){
        printf("%d ",root->data);
        return 1;
    }
    if(h>1){
        int lflag = 0;
        lflag = PrintLeftView(root->left,h-1,0);
        if(lflag == 0)
            lflag = PrintLeftView(root->right,h-1,lflag);
    }
}

void leftView(Node *root)
{
    int h =  height(root);
    for(int i =0;i<h;i++)
        PrintLeftView(root,i+1,0);
}

