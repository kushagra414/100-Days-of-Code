 
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Functio to find first smallest positive
// missing number in the array
int missingNumber(int arr[], int n) { 
    int max=0;
    for(int i=0;i<n;i++)
        max = arr[i]>max?arr[i]:max;
    
    if(max<1)
        return 1;
    
    bool hash[max+1];
    memset(hash,0,max+1);
    for(int i=0;i<n;i++)
        if(arr[i]>0)
            hash[arr[i]]=1;
            
    for(int i=1;i<max+1;i++)
        if(hash[i]==0)
            return i;
    return max+1;
    
} 

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        cout<<missingNumber(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends
