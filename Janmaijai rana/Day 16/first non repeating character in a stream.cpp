#include <iostream>
#include <queue>

using namespace std;

int main() {
    
   int t=0;
	cin>>t;
	while(t){
	  int n=0;
	  cin>>n;
	 
	 char p[n];
	  for(int i=0;i<n;i++){
	    cin>>p[i];}
	    
	    int char_array[26]={0};
	    queue<char>q;
	    
	    for(int i=0;i<n;i++){
	        q.push(p[i]);
	        
	        char_array[p[i]-97]++;
	        
	        while(!q.empty()){
	        if(char_array[q.front()-97]>1)
	          q.pop();
	         else{
	          cout<<q.front()<<" ";
	            break;}
	        }
	          
	          if(q.empty())
	           cout<<"-1"<<" ";
	      
	    }
	      
	
	
	cout<<endl;
	t--;
	}
	return 0;
}
