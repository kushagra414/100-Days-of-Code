



// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> modifyQueue(queue<ll> q, int k);
int main(){
    ll t;
    cin>>t;
    while(t-->0){
        ll n,k;
        cin>>n>>k;
        queue<ll> q;
        while(n-->0){
            ll a;
            cin>>a;
            q.push(a);
        }
        queue<ll> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends
//User function Template for C++

queue<ll> modifyQueue(queue<ll> q, int k)
{
    int n=0,d=0;
    n=q.size();
    d=n-k;
    int arr[k];
    int arr1[d];
    
    for(int i=0;i<k;i++){
        arr[i]=q.front();
        q.pop();}

     
    if(d!=0){
    for(int m=0;m<d;m++){
      arr1[m]=q.front();
      q.pop();}}
      
     
    while(k>0){
       q.push(arr[k-1]);
       k--;}
       
    for(int j=0;j<d;j++)
       q.push(arr1[j]);
       
    return q;
    
    
}
