#include <stdio.h>

void findLocalMinima(int array[],int N,int localMinima[]);
void findLocalMaxima(int array[],int N,int localMaxima[]);

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int array[N],flag=0;
	    for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);
	    int localMinima[N],localMaxima[N];
	    findLocalMinima(array,N,localMinima);
	    findLocalMaxima(array,N,localMaxima);
	    
	    int i=0,j=0;
	    for(int k=0;k<N;k++){
	        for(;i<N;i++)
	            if(localMinima[i]>=0)
	                break;
	        
	        j=i;
	        for(;j<N;j++)
	            if(localMaxima[j]>=0)
	                break;
	        if(i<N&&j<N){
	            printf("(%d %d) ",i++,j);
	            flag=1;
	        }
	        else
	            break;
	    }
	    if(flag==0)
	        printf("No Profit");
	    printf("\n");
	}
	return 0;
}

void findLocalMinima(int array[], int N, int localMinima[]){
    int localMin=array[0];
    memset(localMinima,-1,sizeof(int)*N);
    localMinima[0]=localMin;
    for(int i=1;i<N;i++)
        if(array[i]<localMin){
            localMin = array[i];
            localMinima[i-1]=-1;
            localMinima[i]=localMin;
        }
        else{
            localMin=array[i];
            localMinima[i]=-1;
        }
    /*printf("Local Minima\n");
    for(int i=0;i<N;i++){
        if(localMinima[i]>=0)
            printf("lM[%d]:%d ",i,localMinima[i]);
    }
    printf("\n");*/
}

void findLocalMaxima(int array[],int N,int localMaxima[]){
    int localMax=array[0];
    memset(localMaxima,-1,sizeof(int)*N);
    localMaxima[0]=localMax;
    for(int i=1;i<N;i++)
        if(array[i]>localMax){
            localMax = array[i];
            localMaxima[i-1]=-1;
            localMaxima[i]=localMax;
        }
        else{
            localMax=array[i];
            localMaxima[i]=-1;
        }
    /*printf("Local Maxima\n");
    for(int i=0;i<N;i++){
        if(localMaxima[i]>=0)
            printf("lM[%d]:%d ",i,localMaxima[i]);
    }
    printf("\n");*/
}

