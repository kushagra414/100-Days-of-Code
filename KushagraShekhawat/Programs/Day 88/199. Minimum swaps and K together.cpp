#include<bits/stdc++.h>
using namespace std;

int findMinSwaps(int arr[], int n, int k);

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
	    cout<<findMinSwaps(arr,N,K)<<endl;
	}
	return 0;
}

int findMinSwaps(int arr[], int n, int k){
    //window is total number of ele less than or equal to k
    //swaps are the elements that are greater than k in the window
    int window=0,swaps=0,minSwaps;
    for(int i=0;i<n;i++)
        window+=arr[i]<=k?1:0;
    
    for(int i=0;i<window;i++)
        swaps+=arr[i]>k?1:0;
        
    minSwaps=swaps;
    
    //Find a window with minimum number of swaps
    for(int i=0,j=window;j<n;i++,j++){
        if(arr[i]>k)
            swaps--;
        if(arr[j]>k)
            swaps++;
        
        minSwaps=min(minSwaps,swaps);
    }
    return minSwaps;
}