#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int array[N],totalWater=0;
	    for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);
	    
	    int left[N],right[N];
	    left[0] = array[0]; 
	    for(int i=1;i<N;i++){
	        left[i] = max(left[i-1],array[i]);
	    }
	    right[N-1]=array[N-1];
	    for(int j=N-2;j>=0;j--){
	        right[j] = max(right[j+1],array[j]);
	    }
	    for(int i=0;i<N;i++){
	        totalWater+=min(left[i],right[i])-array[i];   
	    }
	    printf("%d\n",totalWater);
	}
	return 0;
}
