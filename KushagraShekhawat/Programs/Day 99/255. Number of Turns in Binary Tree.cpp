// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int NumberOFTurns(struct Node* root, int first, int second);

 // } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/
// function should return the number of turns required to go from first node to second node

Node *lca(struct Node* root, int first, int second){
    if(!root)
        return NULL;
    if(root->data==first or root->data==second)
        return root;
    Node *left=lca(root->left,first,second);
    Node *right=lca(root->right,first,second);
    if(left and right)
        return root;
    else if(left or right)
        return left==NULL?right:left;
    else
        return NULL;
}

bool found=0;
int turns=0;

char findTurnsLCA(Node *root, int num,char LorR){
    if(!root)
        return 'n';
    
    if(root->data==num){
        found=1;
        return LorR;
    }
    char left='n',right='n';
    if(!found)
        left = findTurnsLCA(root->left,num,'l');
    if(!found)
        right = findTurnsLCA(root->right,num,'r');
    if(found){
        if(left=='l' and LorR=='r')
            turns++;
        else if(right=='r' and LorR=='l')
            turns++;
        return LorR;
    }
    return 'n';
}

int NumberOFTurns(struct Node* root, int first, int second)
{
    turns=0;
    found=0;
    Node *LCA = lca(root,first,second);
    if(LCA->data==first){
        findTurnsLCA(LCA,second,'n');
    }
    else if(LCA->data==second){
        findTurnsLCA(LCA,first,'n');
    }
    else{
        findTurnsLCA(LCA,first,'n');
        found=0;
        findTurnsLCA(LCA,second,'n');
        turns+=1;
    }
    return turns==0?-1:turns;
}

// { Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        if ((turn = NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}
  // } Driver Code Ends