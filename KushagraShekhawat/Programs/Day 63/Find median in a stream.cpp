#include <bits/stdc++.h>
using namespace std;

int main() {
	int T,median,num;
	scanf("%d",&T);
	priority_queue<int>Maxpq,Minpq;
	while(T--){
	    scanf("%d",&num);
	    if(Maxpq.empty() and Minpq.empty())
	        Maxpq.push(num);
	    else if(num<=Maxpq.top())
	       Maxpq.push(num);
	    else
	       Minpq.push(-1*num);
	       
	    if(Maxpq.size()>Minpq.size()+1){
	        Minpq.push(-1*Maxpq.top());
	        Maxpq.pop();
	    }
	    else if(Minpq.size()>Maxpq.size()+1){
	        Maxpq.push(-1*Minpq.top());
	        Minpq.pop();
	    }
	    if(Minpq.size()==Maxpq.size())
	        median = (Maxpq.top()-1*Minpq.top())/2;
	    else
	        median = Minpq.size()>Maxpq.size()?-1*Minpq.top():Maxpq.top();
	   
	   cout<<median<<endl;
	}
	return 0;
}