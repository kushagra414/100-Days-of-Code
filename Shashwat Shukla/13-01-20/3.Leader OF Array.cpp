#include<iostream>
using namespace std;

main()
{
	int t,n; cin>>t;
	while(t--)
	{
		cin>>n; int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int j,f=0;
		for(int i=0;i<n;i++)
		{	
			j=n-1, f=0;
			if(i==n-1)
			cout<<a[n-1];
			else
			{
				while(i<j)
				{
					if(a[j]>a[i])
					{ f=1; break; }
					else
					j--; 
				}
				if(f!=1)
				cout<<a[i]<<" ";
			}
		}
		cout<<endl;
	}
}
