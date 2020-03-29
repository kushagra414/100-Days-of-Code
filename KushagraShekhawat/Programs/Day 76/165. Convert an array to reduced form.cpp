#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr[N],copy[N];
	    for(int i=0;i<N;i++){
	        cin>>arr[i];
	        copy[i]=arr[i];
	    }
	    sort(copy,copy+N);
	    unordered_map<int,int>ump;
	    for(int i=0;i<N;i++){
	        ump[copy[i]]=i;
	    }
	    for(int i=0;i<N;i++){
	        cout<<ump[arr[i]]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}