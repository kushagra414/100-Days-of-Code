#include <stdio.h>
#include <string.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,number=1,inserted;
	    scanf("%d",&N);
	    int hash[N];
	    memset(hash,0,sizeof(int)*N);
	    hash[1] = 1;number++;inserted=1;
	    while(number<=N){
	        int i=inserted+1,count=0;
	        while(count<number+1){
	            if(i==N)
	                i=0;
	            if(hash[i]==0){
	                count++;
	                if(hash[i]==0&&count==number+1){
	                    hash[i]=number;inserted=i;
	                }
	            }
	            i++;
	        }
	        number++;
	    }
	    if(N==1)
	        printf("1");
	    else
	        for(int i=0;i<N;i++)
	            printf("%d ",hash[i]);
	    printf("\n");
	}
	return 0;
}
