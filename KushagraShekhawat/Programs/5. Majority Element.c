#include <stdio.h>

int main() {
	//Use Hashing
	int T;
	scanf("%d",&T);
	while(T){
	    int N,max=0;
	    scanf("%d",&N);
	    int array[N],found_major_element=0;
	    //Inputs
	    for(int i=0;i<N;i++){
	        scanf("%d",&array[i]);
	    }
	    
	    //Find max
	    for(int i=0;i<N;i++){
	        if(array[i]>max)
	        max = array[i];
	    }
	    //Array of max length
        max = max+1;
        if(max<N)
            max = N;
	    int hash[max];
        for(int i=0;i<max;i++){
        hash[i]=0;
        }
	    //hashing function
	    for(int i=0;i<N;i++){
	    hash[array[i]]++;
        }
	    
	    //Check for majority
	    for(int i=0;i<N;i++){
	        if(hash[array[i]]>N/2){
	            printf("%d\n",array[i]);
	            found_major_element=1;
	            break;
	        }
	    }
        if(found_major_element==0)
	    printf("-1\n");
	    T--;
	}
	return 0;
}