#include<bits/stdc++.h>
using namespace std;


int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,K;
	    cin>>N;
	    int arr[N];
	    vector<int>vec;
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    cin>>K;  
	    for(int i=0;i<N;i++)
	        for(int j=i+1;j<N;j++)
	            vec.push_back(abs(arr[i]-arr[j]));
	    sort(vec.begin(),vec.end());
	    cout<<vec[K-1]<<endl;
	}
	return 0;
}