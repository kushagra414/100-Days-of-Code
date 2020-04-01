// { Driver Code Starts
//Author- Sajal Agrawal
//sajal.agrawal1997@gmail.com

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int indx,ans;

struct Node{
    int data;
    Node *left,*right;
    
    Node(int d){
        data=d;
        left=right=NULL;
    }
};
int pairsViolatingBST(Node *root,int n);
void insert(Node *root,int a,int b,char ch);

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
		indx=0;
		ans=0;
        Node *root=NULL;
        for(int j=0;j<n;j++){
            int a,b;
            char ch;
            cin>>a>>b>>ch;
            if(root==NULL){
                root=new Node(a);
                switch(ch){
                    case 'L':root->left=new Node(b);
                            break;
                    case 'R':root->right=new Node(b);
                            break;
                }
            }else{
                insert(root,a,b,ch);
            }
        }
		cout<<pairsViolatingBST(root,n)<<"\n";
    }

	return 0;
}

void insert(Node *root,int a,int b,char ch){
    if(root==NULL)return;
    if(root->data==a){
        switch(ch){
            case 'L':root->left=new Node(b);
                    break;
            case 'R':root->right=new Node(b);
                    break;
        }
    }else{
        insert(root->left,a,b,ch);
        insert(root->right,a,b,ch);
    }
}
// } Driver Code Ends
/* The structure of Node
struct Node{
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
}; */

void InOrder(Node *root, vector<int>&vec){
    if(!root)
        return;
    InOrder(root->left,vec);
    vec.push_back(root->data);
    InOrder(root->right,vec);
}

/*You are required to complete below method */
int pairsViolatingBST(Node *root,int n){
    vector<int>vec;
    InOrder(root,vec);
    int count=0;
    for(auto it1=vec.begin();it1!=vec.end();++it1)
        for(auto it2=it1+1;it2!=vec.end();++it2){
            if(*it1>*it2)
                count++;
        }
        return count;
}
