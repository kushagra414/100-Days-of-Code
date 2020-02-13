// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

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


void printSpiral(struct Node *root);

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

    printSpiral(root);
    cout<<endl;
  }
    return 0;
}

// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
int cal_height(Node *temp){
    if(temp==NULL){
        return 0;
    }
    else{
        int left_height=cal_height(temp->left);
        int right_height=cal_height(temp->right);
        if(left_height>right_height){
            return(left_height + 1);
        }
        else{
            return(right_height + 1);
        }
    }
}
int printlevel(Node *temp,int level,bool iteration){
    if(temp==NULL){
        return 0;
    }
    else if(level==1){
        cout<<temp->data<<" ";
    }
    else{
        if(iteration){
            printlevel(temp->left, level-1, iteration);
            printlevel(temp->right, level-1, iteration);
        }
        else{
            printlevel(temp->right, level-1, iteration);
            printlevel(temp->left, level-1, iteration);
        }
    }
}
void printSpiral(Node *temp)
{
    bool iteration=0;
    int i;
    int level=cal_height(temp);
    for(i=1;i<=level;i++){
        printlevel(temp,i,iteration);
        if(i%2==1){
            iteration=1;
        }
        else{
            iteration=0;
        }
    }
}
