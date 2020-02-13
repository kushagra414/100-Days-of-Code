// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
	int bal = 0 , f=-1 ;
   for(int i=0;i<n; i++)
   {
   	if( p[i].petrol >= p[i].distance && f==-1 )
   	{
   		bal += p[i].petrol ; bal -=p[i].distance ; f=i; continue;
	}
	if( bal+p[i].petrol >= p[i].distance && f != -1)
	{	
		bal += p[i].petrol ; bal -=p[i].distance ;
	}
	else if(bal+p[i].petrol < p[i].distance && f!=-1)
	{	
		f=-1; bal = 0;
	}
   }
   
   for(int i=0;i<f;i++)
   {
   	if( bal+p[i].petrol >= p[i].distance )
	{	
		bal += p[i].petrol ; bal -=p[i].distance ;
	}
	else
	{	
		f=-1; break;
	}
   }
   
   return f;
   
}
