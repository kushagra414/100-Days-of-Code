// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

Node *CreateLL(int data[]){
    Node *head = (Node *)malloc(sizeof(struct Node));
    Node *node=head,*previous;
    for(int i=1;i<1001;i++){
        if(data[i]!=0){
            while(data[i]>0){
                node->data=i;
                data[i]--;
                previous=node;
                node->bottom = (Node *)malloc(sizeof(struct Node));
                node=node->bottom;
            }
        }
    }
    delete node;
    previous->bottom=NULL;
    return head;
}

Node *flatten(Node *root)
{
   if(root==NULL)
        return NULL;
   int hash[1001];
   memset(hash,0,sizeof(int)*1001);
   Node *bottomRoot;
   while(root!=NULL){
       hash[root->data]++;
       bottomRoot=root->bottom;
       while(bottomRoot!=NULL){
           hash[bottomRoot->data]++;
           bottomRoot=bottomRoot->bottom;
       }
       root=root->next;
   }
   return CreateLL(hash);
}


