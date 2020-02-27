#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    string str;
	    cin>>str;
	    int len = str.length(),i=0,j=0;
	    stack<int>s;
	    while(j<len){
	        if(str[j]=='('){
	            s.push(++i);
	            cout<<i<<" ";
	        }
	        else if(!s.empty() and str[j]==')'){
	            cout<<s.top()<<" ";
	            s.pop();
	        }
	        j++;
	    }
	    cout<<endl;
	}
	return 0;
}