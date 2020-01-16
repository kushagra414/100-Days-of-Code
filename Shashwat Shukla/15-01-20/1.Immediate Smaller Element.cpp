#include<iostream>
using namespace std;

main()
{
	int t; cin>>t;
	while(t--)
	{
		int n ; cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			if(a[i]<=a[i+1] || i==n-1 ) 
			{
				cout<<-1<<" ";
				
			}
			else
				cout<<a[i+1]<<" ";
		}
		cout<<endl;
	}
} 
