#include <stdio.h>
#include <string.h>

bool HasDivSumPair(int Up[], int Down[], int k, int N){
    for(int i=0;i<N;i++)
	    if(Up[i]!=0&&Up[i]==Down[i])
	        if(k%2==0&&i==k/2&&Up[i]%2!=0)
	            return 0;
	    else if(Up[i]!=0&&Up[i]!=Down[i])
	        return 0;
	  
    return 1;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int array[N];
	    for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);
	    int k;
	    scanf("%d",&k);
	    int Up[k+1],Down[k+1];
	    memset(Up,0,sizeof(int)*(k+1));
	    memset(Down,0,sizeof(int)*(k+1));
	    for(int i=0;i<N;i++){
	        if(array[i]%k!=0){
	            int quotient = array[i]/k;
	            int multiple = (quotient+1)*k;
	            int up = multiple-array[i];
	            Up[up]++;
	            int down = array[i]%k;
	            Down[down]++;
	        }
	        else{
	            Up[k]++;
	            Down[k]++;
	        }
	    }
	    if(HasDivSumPair(Up,Down,k,N)==0)
	        printf("False\n");
	    else
	        printf("True\n");
	}
	return 0;
}