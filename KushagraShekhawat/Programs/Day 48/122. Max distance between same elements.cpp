// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maxDistance(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout<<maxDistance(arr,n)<<endl;
    }
    return 0;
}// } Driver Code Ends
// your task is to complete this function
int maxDistance(int arr[], int n)
{
    int maxDist = 0;
    unordered_map<int, int>m;
    for(int i=0;i<n;i++)
        if(m[arr[i]])
            maxDist = i-m[arr[i]]+1>maxDist?i-m[arr[i]]+1:maxDist;
        else
            m[arr[i]]=i+1;
    return maxDist;
}
