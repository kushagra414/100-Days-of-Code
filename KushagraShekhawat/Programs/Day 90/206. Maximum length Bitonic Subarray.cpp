#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,previous=0,length=0,maxLen=0;
	    bool flag=0;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    
	    length=1;
	    for(int i=1;i<N;i++){
	        if(arr[i]>arr[previous] and flag==0){
	            length++;
	        }
	        else if(arr[i]>arr[previous] and flag==1){
	            flag=0;
	            length=2;
	        }
	        else if(arr[i]<arr[previous]){
	            length++;
	            flag=1;
	        }
	        previous++;
	        
	        maxLen=max(maxLen,length);
	    }
	    cout<<max(maxLen,length)<<endl;   
	}
	return 0;
}