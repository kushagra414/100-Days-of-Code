#include <stdio.h>

int main() {
	int T;
	scanf("%d",&T);
	while(T){
	    int N;
	    scanf("%d",&N);
	    int array[N];
	    int no_of_zeros=0,no_of_ones=0,no_of_twos=0,j=0;
	    //Inputs
	    for(int i=0;i<N;i++){
	        scanf("%d",&array[i]);
	    }
	    //Count zeros, ones and twos.
        for(int i=0;i<N;i++){
            if(array[i]==0)
                no_of_zeros++;
            else if(array[i]==1)
                no_of_ones++;
            else
                no_of_twos++;
        }
        //Sort
        while(no_of_zeros || no_of_ones || no_of_twos){
	        if(no_of_zeros){
	            array[j] = 0;
	            j++;
	            no_of_zeros--;
	        }
	        else if(no_of_ones){
	            array[j] = 1;
	            j++;
	            no_of_ones--;
	        }
	        else if(no_of_twos){
	            array[j] = 2;
	            j++;
	            no_of_twos--;
	        }
	    }
	    //print array
	    for(int i=0;i<N;i++)
	        printf("%d ",array[i]);
	   printf("\n");
       T--;
	}
	return 0;
}