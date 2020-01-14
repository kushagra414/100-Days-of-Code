#include <bits/stdc++.h> 
using namespace std;

main()
{
	int t ,k ; cin>>t;
	for(int i=0;i<t;i++)
	{
		int n ; cin>>n; int a[n];
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		sort(a,a+n);
		cin>>k;
		cout<<a[k-1]<<endl;
	}
}
