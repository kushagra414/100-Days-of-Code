#include<bits/stdc++.h>
using namespace std;

int findSubArray(int arr[],int n,int k);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,K;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    cin>>K;
	    
	    cout<<findSubArray(arr,N,K)<<endl;
	}
	return 0;
}

int findSubArray(int arr[],int n,int k){
    int sum=0,maxSum=INT_MIN,best=INT_MAX,previous=0;
    for(int i=0;i<k;i++)
        sum+=arr[i];
    maxSum=sum;

    for(int i=k;i<n;i++){
        sum+=arr[i];
        maxSum=max(maxSum,sum);
        previous+=arr[i-k];
        best=min(previous,best);
        maxSum=max(maxSum,sum-best);
    }
    return maxSum;
}