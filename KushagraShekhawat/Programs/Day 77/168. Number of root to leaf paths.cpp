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


void pathCounts( Node* node);

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

     pathCounts(root);
     cout<< endl;
  }
  return 0;
}
// } Driver Code Ends
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*You are required to complete below method */

bool Compare(pair<int, int>p1, pair<int, int>p2){
    return p1.second<p2.second;
}

void CountPaths(Node *root, unordered_map<int, int>&ump, int count){
    if(root==NULL)
        return;
    count++;
    CountPaths(root->left,ump,count);
    CountPaths(root->right,ump,count);
    if(!root->left and !root->right)
        ump[count]++;
}

void pathCounts(Node *root)
{
    unordered_map<int, int>ump;
    CountPaths(root,ump,0);
    vector<pair<int, int>>vec(ump.begin(), ump.end());
    sort(vec.begin(),vec.end(),Compare);
    for(auto it=vec.begin();it!=vec.end();++it)
        cout<<it->first<<" "<<it->second<<" $";
}