#include <bits/stdc++.h>
using namespace std;

int main() {
	int t=0;
	cin>>t;
	while(t){
	    string str;

	    cin>>str;
	    
	  int count=str.size();

	  
	  stack<int>s;
	  int left=0;
	  
	  for(int i=0;i<count;i++){
	    if(str[i]=='('){
	        left++;
	        cout<<left<<" ";
	        s.push(left);
	    }else if(str[i]==')'){
	        cout<<s.top()<<" ";
	        s.pop();
	    }
	  }
	  
	  
	  
	  
	cout<<endl;      
	t--;
	}
	return 0;
}