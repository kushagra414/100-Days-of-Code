#include <bits/stdc++.h>
using namespace std;
class heapnode
{ public:
    heapnode *left,*right;
    unsigned freq;
    char data;
    heapnode(char data,unsigned freq)
      {
          left=right=NULL;
          this->data=data;
          this->freq=freq;
      }

};
 void printcodes(heapnode* root,string str)
      {
          if(root==NULL)
            return;
          if(root->data!='$')
            cout<<str<<" ";
          printcodes(root->left,str+'0');
          printcodes(root->right,str+'1');

      }
struct compare {
   public:
    bool operator()(heapnode* l, heapnode* r)

    {
        return (l->freq > r->freq);
    }
};
void huffmancodes(string s,int* freq)
{ int n=s.size();
    priority_queue<heapnode*,vector<heapnode*>,compare> minheap;
    for(int i=0;i<n;i++)
        minheap.push(new heapnode(s[i],freq[i]));
    while(minheap.size()!=1)
    {
        heapnode *left=minheap.top();
        minheap.pop();
        heapnode *right=minheap.top();
        minheap.pop();
      heapnode* top=new heapnode( '$',left->freq+right->freq);
       top->left=left;
       top->right=right;
       minheap.push(top);




    }
printcodes(minheap.top(),"");

}
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>s;
        int freq[s.size()];
        for(int i=0;i<s.size();i++)
        {
            cin>>freq[i];
        }
        huffmancodes(s,freq);
        cout<<endl;

    }
}
