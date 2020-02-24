#include <bits/stdc++.h>
using namespace std;

bool comparision(int a,int b){
     string s1=to_string(a);
     string s2=to_string(b);
     
     return (s1+s2 > s2+s1);
}

int main() {
    int t=0;
    cin>>t;
	while(t){
	  int n=0;
	  cin>>n;
	  int arr[n];
	  
	 for(int i=0;i<n;i++){
	     cin>>arr[i];
	 }
	 
	 sort(arr,arr+n,comparision);
	 
	 for(int i=0;i<n;i++)
	   cout<<arr[i];
	   
	 cout<<endl;   
	    t--;
	}
	return 0;
}
