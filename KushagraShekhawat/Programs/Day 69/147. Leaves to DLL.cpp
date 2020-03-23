// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inOrder(Node *root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node *convertToDLL(Node *, Node **);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Node *head = NULL;
        root = convertToDLL(root, &head);
        inOrder(root);
        cout << "\n";
        auto curr = head, last = head;
        while (curr) {
            cout << curr->data << " ";
            last = curr;
            curr = curr->right;
        }
        cout << "\n";
        curr = last;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->left;
        }
        cout << "\n";
    }
    return 0;
}// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

Node *DeadPointer = new Node(0);

void RemoveDeadPointer(Node *root,Node *prev){
    if(root==DeadPointer){
        if(prev->left == DeadPointer)
            prev->left = NULL;
        else if(prev->right == DeadPointer)
            prev->right = NULL;
        return;
        }
    else if(root==NULL)
        return;
    RemoveDeadPointer(root->left,root);
    RemoveDeadPointer(root->right,root);
}

void RemoveTheNode(Node *RemoveThisNode, Node *FromThisNode){
    if(FromThisNode)
        if(FromThisNode->left == RemoveThisNode)
            FromThisNode->left = DeadPointer;
        else
            FromThisNode->right = DeadPointer;
    else
        RemoveThisNode=DeadPointer;
}

void DLL(Node *root, Node **head, Node *preNode){
    if(root==NULL)
        return;
    static Node *prevLL = NULL;
    DLL(root->left,head,root);
    if(root->left==NULL and root->right==NULL){
        if(*head==NULL){
            *head=root;
            prevLL = root;
            RemoveTheNode(root,preNode);
        }
        else{
            prevLL->right = root;
            root->left = prevLL;
            RemoveTheNode(root,preNode);
        }
        prevLL = root;
    }
    DLL(root->right,head,root);
}
Node *convertToDLL(Node *root, Node **head) {
    DLL(root, head,NULL);
    RemoveDeadPointer(root,NULL);
    return root;
}
