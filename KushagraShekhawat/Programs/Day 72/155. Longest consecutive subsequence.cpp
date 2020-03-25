// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}// } Driver Code Ends
int findLongestConseqSubseq(int arr[], int n)
{
  int count=0,max=0,maxCount=0;
  max = *max_element(arr,arr+n);
  if(max<n)
    max = n;
  bool hash[max+1];
  memset(hash,0,(max+1)*sizeof(bool));
  for(int i=0;i<n;i++){
        hash[arr[i]]=1;
  }
  for(int i=1;i<max+1;i++){
      if(hash[i]==1 and hash[i]==hash[i+1]){
            count++;
            maxCount = count>maxCount?count:maxCount;
      }
      else
        count = 0;
  }
    return maxCount+1;
}