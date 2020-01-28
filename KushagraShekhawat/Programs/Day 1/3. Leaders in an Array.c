#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T){
	    int N;
	    scanf("%d",&N);
	    int array[N],max=0,inverse[N],count=0;
	    for(int i=0;i<N;i++){
	        scanf("%d",&array[i]);
	    }
	    
	    for(int i=N-1;i>=0;i--){
	        if(array[i]>=max){
                max = array[i];
	            inverse[count] = max;
	            count++;
	        }
        }
	   for(int i=count-1;i>=0;i--){
	        printf("%d ",inverse[i]);
	    }
	    T--;
	    printf("\n");
	}
	return 0;
}