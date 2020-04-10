#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,sum=0;
	    cin>>N;
	    int arr[N];
	    map<int,int>mp;
	    for(int i=0;i<N;i++){
	        cin>>arr[i];
	        mp[arr[i]]++;
	    }
	    auto previous = mp.end();
	    auto it=mp.end();--it;
	    for(;it!=mp.begin();){
	        if(it->second>0){
	            sum+=it->first;
	            previous = it;--previous;
	            if(previous->first+1==it->first and previous->second>0)
	                previous->second--;
	            it->second--;
	        }
	        if(it->second==0)
	            --it;
	    }
	    previous = mp.begin();
	    while(previous->second>0){
	        sum+=previous->first;
	        previous->second--;
	    }
	    cout<<sum<<endl;
    }
    return 0;
}