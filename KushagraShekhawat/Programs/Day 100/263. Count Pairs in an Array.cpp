#include<iostream>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,count=0;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    for(int i=0;i<N;i++)
	        for(int j=i+1;j<N;j++)
	            if(i*arr[i]>j*arr[j])
	                count++;
        cout<<count<<endl;
	}
	return 0;
}