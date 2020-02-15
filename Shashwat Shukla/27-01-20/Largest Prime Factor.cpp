#include<iostream>
using namespace std;

bool isPrime(int n);

main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		if( isPrime(n) )
		{
			cout<<n<<endl;
		}
		else
		{
			int j;
		/*	if( n%2==0 )
			j = n/2-1;
			else
			j = n/2+1;  */
			for( int i = 3 ; i<= n/2 ; i+=2 )
			{
				if( n%i==0 )
				{
					if( isPrime(i) )
					{ j=i ; }
				}
			}
			cout<<j<<endl;
		}
	}
}

bool isPrime(int n)
{
	if(n==2)
	return 1;
	else
    {	for( int i=3;i<=n/2;i+=2 )
    	{
        	if(n%i==0)
        	return 0;
    	}
    return 1;
    }
}

