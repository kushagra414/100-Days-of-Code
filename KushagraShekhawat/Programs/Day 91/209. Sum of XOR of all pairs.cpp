#include<iostream>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    long long int sum=0;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	   
	    for(int i=0;i<N;i++)
	        for(int j=i+1;j<N;j++){
	            sum+=arr[i]^arr[j];
	        }
	    cout<<sum<<endl;
	}
	return 0;
}