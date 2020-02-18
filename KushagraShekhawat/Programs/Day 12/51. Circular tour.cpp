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
    int totalPetrol=0,totalDistance=0,start=0;
   for(int i=0;i<n;i++){
            totalPetrol+=p[i].petrol;
            totalDistance+=p[i].distance;
   }
   if(totalPetrol<totalDistance)
        return -1;
   totalPetrol=0,totalDistance=0;
   
   for(int i=0;i<n;i++){
        totalPetrol+=p[i].petrol;
        totalDistance+=p[i].distance;
        if(totalPetrol<totalDistance){
            totalPetrol=0;
            totalDistance=0;
            start=i+1;
        }
   }
    return start;
}

