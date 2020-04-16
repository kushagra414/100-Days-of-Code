#include<iostream>
#include<limits.h>
using namespace std;

int min(int arr[],int n){
    int mini=INT_MAX,index=-1;
    for(int i=0;i<n;i++){
        if(mini>arr[i]){
            mini=arr[i];
            index=i;
        }
    }
    return index;
}

int findMinSum(int arr1[],int arr2[],int n);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr1[N],arr2[N];
	    for(int i=0;i<N;i++){
	        cin>>arr1[i];
	    }
	    for(int i=0;i<N;i++){
	        cin>>arr2[i];
	    }
	   
	    cout<<findMinSum(arr1,arr2,N)<<endl;
	}
	return 0;
}

int findMinSum(int arr1[],int arr2[],int n){
    if(n==1)
        return -1;
    int minSum=-1;
    int index1 = min(arr1,n);
    int index2 = min(arr2,n);
    if(index1==index2){
        int val1=arr1[index1],val2=arr2[index2];
        arr1[index1]=INT_MAX,arr2[index2]=INT_MAX;
        int temp1=min(arr1,n);
        int temp2=min(arr2,n);
        if(val1+arr2[temp2]<val2+arr1[temp1])
            minSum=val1+arr2[temp2];
        else
            minSum=val2+arr1[temp1];
    }
    else
        minSum=arr1[index1]+arr2[index2];
    return minSum;
}