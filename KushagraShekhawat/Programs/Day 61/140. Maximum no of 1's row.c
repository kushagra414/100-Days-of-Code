#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,M;
	    scanf("%d%d",&N,&M);
	    int ele,max=0,row=0;
	    for(int i=0;i<N;i++){
	        int temp=0;
	        for(int j=0;j<M;j++){
	            scanf("%d",&ele);
	            if(temp==0&&ele==1){
        	            temp=M-j;
        	            if(max<temp){
        	                max = temp;
        	                row=i;
        	            }
	            }
	        }
	   }
	   printf("%d\n",row);
    }
	return 0;
}