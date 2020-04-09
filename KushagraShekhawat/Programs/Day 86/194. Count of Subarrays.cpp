#include<iostream>
using namespace std;

int findCount(int arr[],int n,int k);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,K;
	    cin>>N>>K;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    cout<<findCount(arr,N,K)<<endl;
	}
	return 0;
}

int findCount(int arr[],int n,int k){
    int i=0,count=0,sum=0;
    while(i<n){
        if(arr[i]>k){
            i++;
            continue;
        }
        count=0;
        while(i<n and arr[i]<=k){
            i++;
            count++;
        }
        sum+=count*(count+1)/2;
    }
    return n*(n+1)/2-sum;
}