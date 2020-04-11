#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,previous;
	    long long int sum=0,maxSum=0;
	    bool flag=0;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    
	    previous=0;sum=arr[0];
	    for(int i=1;i<N;i++){
	        if(arr[i]>arr[previous] and flag==0){
	            sum+=arr[i];
	        }
	        else if(arr[i]>arr[previous] and flag==1){
	            flag=0;
	            sum=0;sum=arr[i]+arr[previous];
	        }
	        else if(arr[i]<arr[previous]){
	            sum+=arr[i];
	            flag=1;
	        }
	        previous++;
	        
	        maxSum=max(maxSum,sum);
	    }
	    cout<<max(maxSum,sum)<<endl;   
	}
	return 0;
}