#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,K,count=0;
	    cin>>N>>K;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    for(int i=0;i<N;i++)
	        for(int j=i+1;j<N;j++)
	            if(arr[i]+arr[j]==K)
	                count++;
	    cout<<count<<endl;
	}
	return 0;
}