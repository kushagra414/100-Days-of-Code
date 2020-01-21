#include <stdio.h>
#include <string.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,M,x;
	    scanf("%d%d",&N,&M);
	    //scanf("%d",&M);
	    int array[100+1];
	    memset(array,0,101*sizeof(int));
	    int size = N*M,element;
	    for(int i=0;i<size;i++){
	        scanf("%d",&element);
	        if(array[element]==0)
	            array[element] = element;
	        //else skip element
	    }
	    scanf("%d",&x);
	    if(array[x]==x)
	        printf("1\n");
	    else
	        printf("0\n");
	}
	return 0;
}
