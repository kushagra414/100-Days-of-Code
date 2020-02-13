#include<iostream>
using namespace std;

main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n; int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		if(n>1)
		{
			int i=0 , j=n-1 , f=0 , s1=a[0] , s2=a[n-1] ;
		while(i<j)
		{	
			
			if( s1==s2 && j-i==2 )
			{
				break; f=1;
			}
			else if(s1<s2)
			{
				i++; s1=s1+a[i];
			}
			else
			{
				j--; s2=s2+a[j];
			}
		}
			if(f==1 || s1==s2) 
			cout<<i+2<<endl;
			else
			cout<<-1<<endl;
		}
		else
			cout<<1<<endl;
	}
}
