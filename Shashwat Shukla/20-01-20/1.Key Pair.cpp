#include<iostream>
#include<algorithm>
using namespace std;

main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n; 
		int a[n];
		int k ; cin>>k ;
		for(int i=0;i<n;i++)
		cin>>a[i];
		sort(a,a+n);
		
		int i = 0 , j = n-1 , f=0 ;
		while( i<j )
		{
			if( a[i]+a[j] > k )
			{
				j--;
			}
			else if( a[i]+a[j] < k ) 
			{
				i++;
			}
			else
			{
				cout<<"Yes"<<endl ; f=1 ; break ;
			}
		}
		if( f!=1 )
		cout<<"No"<<endl;
	}
}
