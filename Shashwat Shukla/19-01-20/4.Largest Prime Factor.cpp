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
			int i;
			if( n%2==0 )
				i = n/2-1;
			else
				i = n/2+1; 
		
			for(  ; i>2 ; i-=2 )
			{
				if( n%i == 0 )
				{
					if( ( i%2 == 0 || i%3 == 0 || i%5 == 0 || i%7 == 0 )  && i>=7 )
						continue;
					else
					{
						if( isPrime(i) )
						{
						cout<<i<<endl; break; 
						}
					}
				}
			}
		}
	}
}

bool isPrime(int n)
{
	if(n==2)
	return 1;
	else
    {	for( int i=3 ; i<=n/2 ; i+=2 )
    	{
        	if(n%i==0)
        	return 0;
    	}
    return 1;
    }
}

