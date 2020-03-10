#include <stdio.h>
#include <string.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,K;
	    scanf("%d%d",&N,&K);
	    int arr[K],ones[N];
	    memset(ones,0,N*sizeof(int));
	    for(int i=0;i<K;i++)
	        scanf("%d",&arr[i]);
	        
	    for(int i=0;i<K;i++){
	        //int j = arr[i];
	        for(int k=arr[i]-1;k<N;k++)
	            ones[k]+=1;
	    }
	    for(int i=0;i<N;i++)
	        printf("%d ",ones[i]);
	    printf("\n");
	}
	return 0;
}