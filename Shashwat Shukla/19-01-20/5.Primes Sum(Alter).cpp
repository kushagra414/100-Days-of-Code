#include<iostream>
using namespace std;

bool isPrime(int n);

main()
{
	int t; cin>>t;
	while(t--)
	{
		int n ;
		cin>>n; int o ;
		// "Using Goldbach Conjecture"
	if(n>3)
	{
		if(n%2==0)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			if( isPrime(n-2) )
			{
				cout<<"Yes"<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
	}
	else
		cout<<"No"<<endl;
	}
}

bool isPrime(int n)
{
    for(int i=2;i<=n/2;i+=2)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}
