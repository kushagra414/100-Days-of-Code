// { Driver Code Starts
/* Program to find next right of a given key */
#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct node
{
	int key;
	struct node *left;
	struct node *right;
	
	node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// Method to find next right of given key k, it returns NULL if k is
// not present in tree or k is the rightmost node of its level
node* nextRight(node *root, int k);

// A utility function to test above functions
void test(node *root, int k)
{
	node *nr = nextRight(root, k);
	if (nr != NULL)
	cout << nr->key << endl;
	else
	cout << "-1"<<endl;
}
void insert(struct node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new node(n2);
                    break;
          case 'R': root->right=new node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
 int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new node(n1);
            switch(lr){
                    case 'L': root->left=new node(n2);
                    break;
                    case 'R': root->right=new node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
    cin>>k;
    test(root,k);
    }
    return 0;
}
// } Driver Code Ends
// Method to find next right of given key k, it returns NULL if k is
// not present in tree or k is the rightmost node of its level
  
/* Function to print level  
order traversal a tree*/

void printGivenLevel(node* root, int level, queue<node *>&q);  
int height(node* node);

node *printLevelOrder(node* root,int k)  
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++){
        queue<node *>q;
        printGivenLevel(root, i,q);
        int foundroot=0;
        while(!q.empty()){
            node *Node = q.front();
            if(foundroot){
                return q.front();
            }
            else if(Node and Node->key==k){
                q.pop();
                foundroot=1;
            }
            else
                q.pop();
        }
        if(foundroot){
            return NULL;
        }
    }
    return NULL;
}  
  
/* Print nodes at a given level */
void printGivenLevel(node* root, int level, queue<node *>&q)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        q.push(root);
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1,q);  
        printGivenLevel(root->right, level-1,q);  
    }  
}  
  
/* Compute the "height" of a tree -- the number of  
    nodes along the longest path from the root node  
    down to the farthest leaf node.*/
int height(node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the height of each subtree */
        int lheight = height(node->left);  
        int rheight = height(node->right);  
  
        /* use the larger one */
        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
    }  
}  

node* nextRight(node *root, int k)
{
    return printLevelOrder(root,k);
}