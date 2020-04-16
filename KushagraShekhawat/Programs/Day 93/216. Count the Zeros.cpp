#include<iostream>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,i=0;
	    cin>>N;
	    int arr[N];
	    for(i=0;i<N;i++)
	        cin>>arr[i];
	    
	    for(i=0;i<N;i++){
	        if(arr[i]==0)
	            break;
	    }
	    cout<<N-i<<endl;
	}
	return 0;
}