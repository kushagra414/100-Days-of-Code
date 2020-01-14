#include <stdio.h>

int main() {
    int T;
    scanf("%d",&T);
    while(T){
        int N,S,sum=0,flag=0;
        scanf("%d",&N);
        scanf("%d",&S);
        int array[N];
        for(int i=0;i<N;i++){
            scanf("%d",&array[i]);
        }
        for(int i=0,j=0;i<N,j<N;i++){
            if(sum<S){
                sum += array[i];
            }
            else if(sum>S){
                sum = 0;
                i=j;
                j++;
            }
            else{
                printf("%d %d",j+1,i);
                flag=1;
                break;
            }
        }
        T--;
        if(flag==0)
            printf("-1");
        printf("\n");
    }
	return 0;
}