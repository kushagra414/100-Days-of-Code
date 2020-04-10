// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long int countSubarrWithEqualZeroAndOne(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	cout<< countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
// } Driver Code Ends
long long int countSubarrWithEqualZeroAndOne(int array[], int N)
{
    int zeroSubArr=0,sum=0;
    unordered_map<int, int>mp;
	mp[0]=1;
	for(int i=0;i<N;i++){
	    array[i]=array[i]==0?-1:1;
	    sum+=array[i];
	    if(sum==0||mp[sum]){
	        mp[sum]++;
	        zeroSubArr+=mp[sum]-1;
	    }
	    else
	        mp[sum]++;
	}
	return zeroSubArr;
}