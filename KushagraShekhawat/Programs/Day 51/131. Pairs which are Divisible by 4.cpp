#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int array[N],count=0;
	    for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);
	    //sort(array,array+N);
	    for(int i=0,j=N-1;i<j;i++)
	        for(int j=i+1;j<N;j++)
    	        if((array[i]+array[j])%4==0)
    	            count++;
    	            
    	printf("%d\n",count);
	}
	return 0;
}