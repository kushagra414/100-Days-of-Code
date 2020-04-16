#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,pairs=0;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    unordered_map<int,int>ump;
	    for(int i=0;i<N;i++){
	        ump[arr[i]]++;
	    }
	    for(auto it=ump.begin();it!=ump.end();++it){
	        if(it->second>1){
	            pairs+=(it->second)*(it->second-1)/2;
	        }
	    }
	    cout<<pairs<<endl;
	}
	return 0;
}