// { Driver Code Starts
//Code by 1shubhamjoshi1
#include<bits/stdc++.h>

using namespace std;

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

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        *tree = new Node(val);
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}


Node* LCA(Node *root, int , int );

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        int l,r;
        cin>>l>>r;

        cout<<LCA(root,l,r)->data<<endl;
    }
}
// } Driver Code Ends
/*The structure of a BST Node is as follows:

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
*/

/*You are required to complete
this function*/
bool foundn1 =0;
int i=0;
void Findn1(Node *root, vector<Node *>&v, int n1){
    if(root==NULL)
        return;
    if(root->data==n1)
        foundn1=1;
    if(!foundn1)
        Findn1(root->left,v,n1);

    if(!foundn1)
        Findn1(root->right,v,n1);
        
    if(foundn1)
        v.push_back(root);
}
Node* LCA(Node *root, int n1, int n2)
{
    vector<Node *> v1,v2;
    foundn1=0;
    Findn1(root,v1,n1);
    foundn1=0;
    Findn1(root,v2,n2);
    long int i=v1.size()-1,j=v2.size()-1;
    for(; i>=0&&j>=0; i--,j--){
        Node *node1 = v1[i],*node2 = v2[j];
        if(node1->data!=node2->data)
            break;
    }
    i++;
    return v1[i];
}
