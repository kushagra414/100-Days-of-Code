#include<iostream>
#include<string.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr[N],hash[N];
	    memset(hash,-1,N*sizeof(int));
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    for(int i=0;i<N;i++){
	        if(arr[i]!=-1){
	            hash[arr[i]]=arr[i];
	        }
	    }
	    for(int i=0;i<N;i++)
	        cout<<hash[i]<<" ";
	    cout<<endl;
	}
	return 0;
}