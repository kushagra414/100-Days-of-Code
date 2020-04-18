#include<iostream>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++){
	        cin>>arr[i];
	        arr[i]--;
	    }
	    for(int i=0;i<N;i++)
	        arr[arr[i]%N]+=N;
	        
	    for(int i=0;i<N;i++)
	        cout<<arr[i]/N<<" ";
	    cout<<endl;
	}
	return 0;
}