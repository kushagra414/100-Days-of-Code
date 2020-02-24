// { Driver Code Starts
#include<bits/stdc++.h>
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

void printBoundary(Node *root);

int height(struct Node *root)
{
    if(root==NULL)
        return 0;
    int l = 1+height(root->left);
    int r=1+height(root->right);
    if(l>r)
        return l;
    else
        return r;

}


/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     Node *root = NULL;
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

        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

    printBoundary(root);
   cout<<endl;

  }
    return 0;
}

// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void printLeftBoundary(Node *root, int level, int *max){
    if(root==NULL)
        return;
    
    if((!root->left and !root->right) or (*max<level)){
        cout<<root->data<<" ";
        *max=level;
    }
    printLeftBoundary(root->left,level+1,max);
    printLeftBoundary(root->right,level+1,max);
}

void printRightBoundary(Node *root,  int level, int *max,stack<int>&s){
    if(root==NULL)
        return;
    
    if((!root->left and !root->right) or (*max<level)){
        s.push(root->data);
        *max=level;
    }
    printRightBoundary(root->right,level+1,max,s);
    printRightBoundary(root->left,level+1,max,s);
}

void printBoundary(Node *root)
{
     cout<<root->data<<" ";
     int max=0;
     printLeftBoundary(root->left,1,&max);
     max=0;
     stack<int>s;
     printRightBoundary(root->right,1,&max,s);
     while(!s.empty()){
         cout<<s.top()<<" ";
         s.pop();
     }
}
