#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    long long int cost=0;
	    scanf("%d",&N);
	    int array[N];
	    for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);
	    priority_queue <long long int, vector<long long int>, greater<long long int>> pq;
	    for(int i=0;i<N;i++)
	        pq.push(array[i]);
	    while(pq.size()>1){
	        long long int min1 = pq.top();
	        pq.pop();
	        long long int min2 = pq.top();
	        pq.pop();
	        cost+=min1+min2;
	        pq.push(min1+min2);
	    }
	    printf("%lld\n",cost);
	}
	return 0;
}