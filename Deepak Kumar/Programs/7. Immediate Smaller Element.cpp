#include <iostream>
using namespace std;

int main() {
	int T=0,N=0,i=0;
	cin>>T;
	while(T--){
		cin>>N;
		int arr[N];
		for(i=0;i<N;i++){
			cin>>arr[i];
		}
		for(i=0;i<N;i++){
			if(i==N-1){
				cout<<"-1"<<" ";
			}
			else if(arr[i]>arr[i+1]){
				cout<<arr[i+1]<<" ";
			}
			else
				cout<<"-1"<<" ";
		}
		cout<<endl;
	}
	return 0;
}
