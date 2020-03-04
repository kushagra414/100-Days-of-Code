#include<bits/stdc++.h>
using namespace std;

stack<int> deleteMid(stack<int>s,int sizeOfStack,int current);

int main() {
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);
            
            
        }
        if(sizeOfStack==1)
        {
            cout<<myStack.top();
        }
        else
        {
        
            stack<int> modified=deleteMid(myStack,myStack.size(),0);
            
            
            while(!modified.empty())
            {
                cout<<modified.top()<<" ";
                modified.pop();
            }
        }
        cout<<endl;
        
    }   
	return 0;
}// } Driver Code Ends
//User function Template for C++

//You need to complete this function
stack<int> deleteMid(stack<int>s,int sizeOfStack,int current)
{
    if(sizeOfStack==1)
        return s;
        
    int middle = ceil(sizeOfStack/2.0);
    stack<int>s2;
    
    if(sizeOfStack%2)
        current++;
    //current++;
    while(!s.empty()){
        if(current!=middle)
            s2.push(s.top());
        current++;
        s.pop();
    }
    while(!s2.empty()){
        s.push(s2.top());
        s2.pop();
    }
    return s;
}

