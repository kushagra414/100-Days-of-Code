#include<iostream>
using namespace std;

main()
{
	int t,n; cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n; int a[n]; int k; cin>>k;
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		int max=a[0],temp=0;
		for(int j=1;j<k;j++)
		{
			if(max<a[j])
			{
				max=a[j]; temp = j;
			}
		}
		for(int j=k;j<n;j++)
		{	cout<<max<<" ";	
			if(temp<(j-k+1) && a[j]<=max)
			{	max=a[temp+1];
				for(int p=temp+1;p<=j;p++)
				{
					if(max<=a[p])
				   {
					max=a[p]; temp = p;
				   }
				}
			}
			else
			if(a[j]>max)
			{
				max=a[j]; temp = j;
			}
		}
		cout<<max<<" "<<endl;;
	}
}
