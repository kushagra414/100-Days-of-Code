#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
	int t=0;
	cin>>t;
	while(t){
	  int n;
	  cin>>n;
	  queue<int>q;
	  for(int i=1;i<=n;i++){
	    q.push(i);
	  }
	 // map<int,int>MAP;
	 int arr[n];
	  int f=1;
	 
	  while(!q.empty()){
	        int k=1;
	                while(k<=f){
	                 q.push(q.front());
	                q.pop();
	                    k++; }
	      int pos=q.front(); 
	       q.pop();
	      arr[pos]=f;             
	      f++;
	  }
	  
	 /* for(auto &s:MAP)
	   cout<<s.second<<" ";*/
	   
	   for(int i=1;i<=n;i++){
	       cout<<arr[i]<<" ";
	   }
	   cout<<endl;
	t--;
	}
	return 0;
}
