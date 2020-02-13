#include <stdio.h>
#include <string.h>

int main() {
	int T;
	scanf("%d",&T);
	    while(T--){
	        int N1,N2;
	        scanf("%d%d",&N1,&N2);
	        int array1[N1],array2[N2],var,max=0;
	        for(int i=0,j=0;i<N1,j<N2;)
	            if(i<N1){
	                scanf("%d",&array1[i]);
	                if(array1[i]>max)
                        max=array1[i];
                    i++;
	            }
	            else
	                scanf("%d",&array2[j++]);

            int hash[max+1];
            memset(hash,0,(max+1)*sizeof(int));

            for(int i=0;i<N1;i++)
                hash[array1[i]]++;

	        for(int i=0;i<N2;i++)
	            while(hash[array2[i]] != 0){
	                printf("%d ",array2[i]);
	                hash[array2[i]]-=1;
	            }


	        for(int i=0;i<max+1;i++)
	            while(hash[i]-- != 0)
	                printf("%d ",i);

	        printf("\n");
	    }
	return 0;
}
