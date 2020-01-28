#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T){
	    int N;
	    scanf("%d",&N);
        // Using Hashing
	    int array[N+1],number[N-1];
	    array[N]=0;
        array[N-1]=0;
	    for(int i=0;i<N-1;i++){
            scanf("%d",&number[i]);
            array[i]=0;
	    }
	    for(int i=0;i<N-1;i++){
            // Hashing
            array[number[i]] = 1;
	        }
        for(int i=1;i<N+1;i++){
            if(array[i]==0){
            printf("%d\n",i);
            break;
            }
        }
        T--;
	    }
	return 0;
}