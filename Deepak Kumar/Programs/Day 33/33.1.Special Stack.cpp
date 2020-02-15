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
    if(s.size()==n){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty()
{
    return s.empty();
}

int pop()
{
    int temp=s.top();
    s.pop();
    return temp;
}

int getMin()
{   
    int temp=s.top();
    s.pop();
    while(!s.empty()){
        if(temp>s.top()){
            temp=s.top();
        }
        s.pop();
    }
    return temp;
}
