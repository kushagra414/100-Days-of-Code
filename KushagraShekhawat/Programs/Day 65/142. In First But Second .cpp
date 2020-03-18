#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,M;
	    scanf("%d%d",&N,&M);
	    long long int ele,arr1[N];
	    unordered_map<long long int,bool>mp;
	    for(int i=0;i<N;i++){
	        scanf("%lld",&arr1[i]);
	    }
	    for(int i=0;i<M;i++){
	        scanf("%lld",&ele);
	        mp[ele]=1;
	    }
	    for(int i=0;i<N;i++){
	        if(!mp[arr1[i]])
	            cout<<arr1[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}