#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,sum=0;
	    cin>>N;
	    int array[N],zeroSubArr=0;
	    for(int i=0;i<N;i++)
	        cin>>array[i];
	    unordered_map<int, int>mp;
	    mp[0]=1;
	    for(int i=0;i<N;i++){
	        sum+=array[i];
	        if(sum==0||mp[sum]){
	            mp[sum]++;
	            zeroSubArr+=mp[sum]-1;
	        }
	        else
	            mp[sum]++;
	        //cout<<"mp[sum]:"<<mp[sum]<<" ";
	    }
	    cout<<zeroSubArr<<endl;
	}
	return 0;
}