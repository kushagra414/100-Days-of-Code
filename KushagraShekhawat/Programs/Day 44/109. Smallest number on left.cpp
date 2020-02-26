#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int array[N];
	    for(int i=0;i<N;i++)
	        cin>>array[i];
	    
	    stack<int>s;
	    for(int i=0;i<N;i++){
	        if(s.empty()){
	            cout<<"-1 ";
	            s.push(array[i]);
	        }
	        else if(array[i]>=s.top()){
	            cout<<s.top()<<" ";
	            s.push(array[i]);
	        }
	        else{
	            while(!s.empty() and s.top()>=array[i])
	                s.pop();
	            if(!s.empty())
	                cout<<s.top()<<" ";
	            else
	                cout<<"-1 ";
	            s.push(array[i]);
	        }
	    }
	    cout<<endl;
	}
	return 0;
}