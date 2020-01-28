#include<iostream>
using namespace std;

main()
{
	int t; cin>>t;
	while(t--)
	{
		int  n1 , n2 ,n3, f=0 ; cin>>n1>>n2>>n3;
		int a[n1] , b[n2] , c[n3];
		for(int i=0,j=0,k=0; i<n1,j<n2,k<n3;)
            if(i<n1)
                scanf("%d",&a[i++]);
            else if(j<n2)
                scanf("%d",&b[j++]);
            else if(k<n3)
                scanf("%d",&c[k++]);
		int j=0 , k=0;
		for(int i=0 ; i<n1 ; i++)
		{
			if(a[i]==a[i-1])
			 continue;
			else
			for( ; j<n2 ; j++)
			{
				if( b[j] == a[i] )
				{
					for( ; k<n3 ; k++)
					{
						if( a[i] == c[k] )
						{
							cout<<a[i]<<" "; k++; f=1 ; break;
						}
						if( c[k]>a[i] )
							break;
					}
					j++; break; 
				}
				if( b[j]>a[i] )
				break;
			}
			if( j==n2 || k==n3 )
			break;
		}
		if(f != 1)
		cout<<-1<<endl;
		else 
		cout<<endl;
	}
}
