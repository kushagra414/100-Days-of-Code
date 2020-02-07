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
    int i=0,ans=0,total_petrol=0,total_distance=0;
    for(i=0;i<n;i++){
        total_petrol += p[i].petrol;
        total_distance += p[i].distance;
    }
    if(total_petrol<total_distance){
        return -1;
    }
    total_petrol=0,total_distance=0;
    for(i=0;i<n;i++){
        total_petrol += p[i].petrol;
        total_distance += p[i].distance;
        if(total_petrol<total_distance){
            total_petrol=total_distance=0;
            ans=i+1;
        }
    }
    return ans;
}
