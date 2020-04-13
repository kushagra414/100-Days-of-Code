#include<bits/stdc++.h>
using namespace std;

int findSubArray(int arr[], int N, int K);

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
	    
	    cout<<findSubArray(arr,N,K)<<endl;
	}
	return 0;
}

int findSubArray(int arr[], int N, int K){
    int sum=0,max=0;
    unordered_map<int,int>ump;
    int mod_arr[N];
    for(int i=0;i<N;i++){
        sum+=arr[i];
        mod_arr[i]=((sum%K)+K)%K;
    }
    
    for(int i=0;i<N;i++){
        if(mod_arr[i]==0)
            max=i+1;
        else if(ump.find(mod_arr[i])==ump.end())
            ump[mod_arr[i]]=i;
        else{
            if(max<i-ump[mod_arr[i]])
                max=i-ump[mod_arr[i]];
        }
    }
    return max;
}