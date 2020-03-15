#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int array[N];
	    for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);
	    for(int i=0;i<N;i++){
	        int count=0;
	        for(int j=i;j<N;j++)
	            if(array[i]>array[j])
	                count++;
	        printf("%d ",count);
	    }
	    printf("\n");
	}
	return 0;
}
