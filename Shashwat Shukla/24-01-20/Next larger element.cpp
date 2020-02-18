#include<iostream>
#include<stack>
using namespace std;

main()
{
	int t; cin>>t;
	while(t--)
	{
		int n ; cin>>n ;
		int a[n] , b[n] ;
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		stack<int> st;
		
		for(int i=n-1;i>=0;i--)
		{
			while(!st.empty() && a[i]>=st.top())
			st.pop();
			b [i] = st.empty() ? -1 : st.top();
			st.push(a[i]);
		}
		
		for( int i=0;i<n;i++)
		{
			cout<<b[i]<<" ";
		}
		cout<<endl;
	}
}
