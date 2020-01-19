// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void SortedStack :: sort()
{
    int i=0,k=s.size();
    int arr[k];
      while(!s.empty()){
          arr[i]=s.top();
          s.pop();
          i++;
      }
      
      std::sort(arr,arr+k);
      
      for(int i=0;i<k;i++){
          s.push(arr[i]);
      }
      
      while(!s.empty()){
          cout<<s.top()<<" ";
          s.pop();
      }
      
}
