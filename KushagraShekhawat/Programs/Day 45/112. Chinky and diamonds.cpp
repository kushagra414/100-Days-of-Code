#include <bits/stdc++.h>
using namespace std;

int findMax(int array[], int N){
    int max=INT_MIN,index=0;
    for(int i=0;i<N;i++){
        if(max<array[i]){
            max = array[i];
            index = i;
            }
    }
    return index;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,K,maxDiamonds=0;
	    scanf("%d%d",&N,&K);
	    int array[N];
	    priority_queue<int>q;
	    for(int i=0;i<N;i++){
	        scanf("%d",&array[i]);
	        q.push(array[i]);
	    }
	    for(int i=0;i<K;i++){
	        int maximum=q.top();
	        maxDiamonds+=maximum;
	        q.pop();
	        q.push(ceil(maximum/2));
	    }
	    printf("%d\n",maxDiamonds);
	}
	return 0;
}