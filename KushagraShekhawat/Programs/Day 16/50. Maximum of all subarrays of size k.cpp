#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,K;
	    scanf("%d%d",&N,&K);
	    int array[N];
	    for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);
	    //Sliding Window Maximum 
	    deque <int> d;
	    int i;
	    for(i=0;i<K;i++){
	        // We need to define starting window after that there will only
	        //be increment of 1 in the window.
	        while(!d.empty()&&array[i]>=array[d.back()])
	            d.pop_back();
	        d.push_back(i);
	    }
	    for(;i<=N;i++){
	        printf("%d ",array[d.front()]);
	        
	        //Checking whether Elements in deque are inside window
	        while(!d.empty()&&K<=i-d.front())
	            d.pop_front();
	        
	        //Popping elements that are inbetween i.e. between maximum and minimum
	        while(!d.empty()&&array[i]>=array[d.back()])
	            d.pop_back();
	        
	        //Push the latest element in deque
	        d.push_back(i);
	    }
	    printf("\n");
	}
	return 0;
}