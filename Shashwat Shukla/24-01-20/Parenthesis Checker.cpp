#include<iostream>
#include<string>
#include<stack>
using namespace std;

main()
{
	int t; cin>>t;
	while(t--)
	{
		string s; cin>>s ; 
		int l = s.length();
		stack<char> st;
		for(int i=0;i<l;i++)
		{
			if(s[i]=='{' || s[i]=='(' || s[i]=='[')
			{ st.push(s[i]);  }
			if(s[i]=='}')
			{
				if(!st.empty() && st.top()=='{' )
				st.pop();
				else 
				{ st.push(s[i]) ; break; }
			}
			if(s[i]==')')
			{
				if( !st.empty() && st.top()=='(' )
				st.pop();
				else 
				{ st.push(s[i]) ; break; }
			}
			if( s[i]==']')
			{
				if( !st.empty() && st.top()=='[' )
				st.pop();
				else 
				{ st.push(s[i]) ; break; }
			}
		}
		if(st.empty() )
			cout<<"balanced"<<endl;
		else
			cout<<"not balanced"<<endl;
	}
}
