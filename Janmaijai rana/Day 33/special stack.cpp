// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}// } Driver Code Ends
/*Complete the function(s) below*/
void push(int a)
{
   s.push(a);   
}

bool isFull(int n)
{
     if(n<=s.size())
     return true;
     else
       return false;
}

bool isEmpty()
{
    if(s.size()==0)
      return true;
      else 
       return false;
}

int pop()
{
    s.pop();
}

int getMin()
{
   int min;
   min=s.top();
   while(!s.empty()){
       if(min>s.top()){
           min=s.top();
       }
       s.pop();
   }
   return min;
}





