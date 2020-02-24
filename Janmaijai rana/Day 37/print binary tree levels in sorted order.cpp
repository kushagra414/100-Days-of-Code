#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int min(int a,int b){
    if(a<b)
    return a;
    else 
    return b;
}

int main() {
	//code
	int t=0;
	cin>>t;
	while(t){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	
	int level=0;
	for(int i=0;i<n;level++){
	    int current_level=pow(2,level)-1;
	    
	    int j=min(current_level+i,n-1);
	    
	    sort(arr+i,arr+j+1);
	    
	    while(i<=j){
	        cout<<arr[i]<<" ";
	        i++;
	    }
	    cout<<endl;
	}
	    t--;
	}
	return 0;
}
