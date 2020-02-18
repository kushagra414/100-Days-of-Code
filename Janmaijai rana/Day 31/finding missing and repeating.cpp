#include <iostream>
using namespace std;

int main() {
    int t=0;
    cin>>t;
	while(t){
	int n,p;
	cin>>n;
	int hash[n+1]={0};
	for(int i=0;i<n;i++){
	  cin>>p;
	  hash[p]++;}
	 int m=0,f=0;
	 
	 for(int i=1;i<=n;i++){
	     if(hash[i]==0 && m<i)
	         m=i;
	      
	    if(hash[i]==2 && f<i)
	      f=i;
	    }
	  
	  cout<<f<<" "<<m;
		
	cout<<endl;
	t--;
	}
	return 0;
}  
