#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    sort(arr,arr+N);
	    int i;
	    for(i=1;i<N;i++){
	        if(arr[i-1]==arr[i] or arr[i-1]+1==arr[i])
	            continue;
	        else
	            break;
	    }
	    if(i==N)
	        cout<<"Yes"<<endl;
	    else
	        cout<<"No"<<endl;
	}
	return 0;
}