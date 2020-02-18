#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N1,N2,N3;
	    scanf("%d",&N1);
	    scanf("%d",&N2);
	    scanf("%d",&N3);
    
        int array1[N1],array2[N2],array3[N3],found_common=0,previous;
        
        for(int i=0,j=0,k=0; i<N1,j<N2,k<N3;)
            if(i<N1)
                scanf("%d",&array1[i++]);
            else if(j<N2)
                scanf("%d",&array2[j++]);
            else if(k<N3)
                scanf("%d",&array3[k++]);
        
        
        for(int i=0,j=0,k=0;i<N1&&j<N2&&k<N3;){
            //printf("array1[%d]:%d array2[%d]:%d array3[%d]:%d\n",i,array1[i],j,array2[j],k,array3[k]);
            if(array2[j]>array1[i]){
                i++;
            }
            else if(array2[j]<array1[i]){
                j++;
            }
            else if(array1[i]==previous)
                i++;
            else if(array2[j]==array1[i]){
                if(array3[k]<array2[j])
                    k++;
                else if(array3[k]>array2[j])
                    i++,j++;
                else if(array3[k]==array2[j]){
                    printf("%d ",array3[k]);
                    previous = array3[k];
                    i++,j++,k++;
                    found_common = 1;
                    
                }
            }
        }
        if(found_common==0)
            printf("-1\n");
        else
            printf("\n");
    }
    return 0;
}