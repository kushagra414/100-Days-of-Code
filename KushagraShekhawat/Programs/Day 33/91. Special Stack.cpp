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
     return s.size()<n?0:1;
}

bool isEmpty()
{
    return s.empty();
}

int pop()
{
    int ele =  !s.empty()?s.top():-1;
    if(ele>0)
        s.pop();
    return ele;
    
}

int getMin()
{
    int min=2147483647; //Max size of int
   stack <int> s1=s;
   while(!s1.empty()){
       min = s1.top()<min?s1.top():min;
       s1.pop();
   }
   return min;
   
}
