#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int Array[N],max=-1;
	    for(int i=0;i<N;i++){
	        scanf("%d",&Array[i]);
	        if(max<Array[i])
	            max = Array[i];
	    }
	    int Hash[max+1];
	    memset(Hash,-1,sizeof(int)*(max+1));
	    for(int i=0;i<N;i++){
	        Hash[Array[i]]=Array[i];
	    }
	    
	    int maxSubArray = 0,count=0;
	    for(int i=0;i<max;i++){
	        if(Hash[i]+1==Hash[i+1]&&Hash[i+1]){
	            count++;
	            maxSubArray=count>maxSubArray?count:maxSubArray;
	        }
	        else
	            count=0;
	    }
	    printf("%d\n",maxSubArray+1);
	}
	return 0;
}