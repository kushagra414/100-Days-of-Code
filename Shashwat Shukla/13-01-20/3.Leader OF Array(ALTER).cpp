#include<iostream>
using namespace std;

main()
{
	int t,n; cin>>t;
	while(t--)
	{
		cin>>n; int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
			int i=n-2 , j=0 , max = a[i+1] ; b[j] = a[n-1]; 
		while(i>=0)
		{
			if(a[i+1]<a[i] && a[i]>=max)
			 {
			 	b[++j] = a[i]; max = a[i];
			 }
			 i--;
		}
		for(int i=j;i>=0;i--)
		cout<<b[i]<<" ";
		cout<<endl;
	}
}
