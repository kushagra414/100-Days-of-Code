#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N,K,sum=0,gain=0,max=0;
	    cin>>N>>K;
	    int array[N];
	    unordered_map<int, int>ump;
	    for(int i=0;i<N;i++)
	        cin>>array[i];
	    ump[0] = -1;
	    for(int i=0;i<N;i++){
	        sum+=array[i];
	        if(ump.find(sum)==ump.end())
	            ump[sum]=i;
	        if(ump.find(sum-K)!=ump.end()){
	            int start = ump[sum-K];
	            gain = i-start;
	            max = gain>max?gain:max;
	        }
	    }
	    cout<<max<<endl;
	}
	return 0;
}