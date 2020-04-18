#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    long long int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];

	    unordered_map<long long int,long long int>ump;
	    for(int i=0;i<N;i++){
	        ump[arr[i]]++;
	    }
	    int i;
	    for(i=0;i<N;i++)
	        if(ump[arr[i]]==1){
	            cout<<arr[i]<<endl;
	            break;
	        }
	    if(i==N)
	        cout<<"0"<<endl;
	}
	return 0;
}