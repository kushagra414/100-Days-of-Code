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

bool hasPathSum(Node *, int );

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
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
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
     int a;
     cin>>a;

     cout<<hasPathSum(root,a)<<endl;

  }
  }
  return 0;
}
// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


/*you are required to 
complete this function */
bool hasPathSum(Node *node, int sum)
{
    if(node==NULL){
        return 0;
    }
    else{
        int ans=0;
        int subsum = sum - node->data;
        if(subsum==0 && node->left==NULL && node->right==NULL){
            return 1;
        }
        if(node->left){
            ans=(ans || hasPathSum(node->left,subsum));
        }
        if(node->right){
            ans=(ans || hasPathSum(node->right,subsum));
        }
        return ans;
    }
}
