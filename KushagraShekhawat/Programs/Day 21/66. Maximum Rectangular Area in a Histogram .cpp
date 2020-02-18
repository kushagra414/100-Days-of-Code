#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    long long int N;
	    scanf("%lld",&N);
	    long long int hist[N];
	    for(int i=0;i<N;i++)
	        scanf("%lld",&hist[i]);
	    stack <long long int> s;
	    long long int area=0,maxArea=-1,ele=0,i=0;
	    for(i=0;i<N;i++){
	        if(s.empty()||hist[i]>hist[s.top()])
	            s.push(i);
	        else{
	               while(!s.empty()&&hist[s.top()]>hist[i]){
	                   ele=s.top();
	                   s.pop();
	                    if(s.empty())
	                        area=hist[ele]*i;
	                    else
	                        area=hist[ele]*(i-s.top()-1);
	                    if(maxArea<area)
	                        maxArea=area;
	                }
	           s.push(i);
	            }
	       }
	       while(!s.empty()){
	           ele=s.top();
	           s.pop();
	           if(s.empty())
	               area=hist[ele]*i;
	           else
	               area=hist[ele]*(i-s.top()-1);
	           if(maxArea<area)
	               maxArea=area;
	    }
	    printf("%lld\n",maxArea);
	}
	return 0;
}