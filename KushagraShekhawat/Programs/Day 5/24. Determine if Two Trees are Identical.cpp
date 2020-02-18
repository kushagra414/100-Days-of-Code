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

bool isIdentical(Node *,Node *);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */

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
     
  //  inorder(root);


    //sec tree

     map<int, Node*> mm;
     int nn;
     scanf("%d\n",&nn);
     struct Node *roott = NULL;
    
     while (nn--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (mm.find(n1) == mm.end())
        {
           parent = new Node(n1);
           mm[n1] = parent;
           if (roott == NULL)
             roott = parent;
        }
        else
           parent = mm[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        mm[n2]  = child;
     }


  
  cout<<isIdentical(root,roott)<<endl;
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

/* Should return true if trees with roots as r1 and 
   r2 are identical */
   
bool InOrderTraversal(Node *r1, Node *r2, bool identical){
    /*if((r1 == NULL && r2 == NULL) || (r1 != NULL && r2 != NULL)){
        return 1;
    }
    else if((r1 != NULL && r2 == NULL) || (r1 == NULL && r2 != NULL)){
        return 0;
    }*/
    if(r1 == NULL || r2 == NULL){
        if(r1 == NULL && r2 == NULL)
            return 1;
        return 0;
    }
    else if(identical){
        identical = InOrderTraversal(r1->left,r2->left,identical);
        //printf("r2->data = %d, r1->data = %d, identical =%d\n",r1->data,r2->data,identical);
        if(r2->data != r1->data || identical == 0){
            return 0;
        }
        identical = InOrderTraversal(r1->right,r2->right,identical);
        if(r2->data != r1->data || identical == 0){
            return 0;
        }
        return 1;
    }
}
   
bool isIdentical(Node *r1, Node *r2)
{
    return InOrderTraversal(r1, r2,1);
}