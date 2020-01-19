#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
	int T;
	scanf("%d",&T);
	while(T){
	    int N;
	    scanf("%d",&N);
	    N = 2*N+2;
	    int array[N],no_of_unpair_found=0;
	    for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);
	    sort(array,array+N);
	    for(int i=0;i<N;i++){
	        if(i==N-1){
	            printf("%d ",array[N-1]);
	            no_of_unpair_found++;
	            if(no_of_unpair_found == 2)
	                break;
	        }
	        if(array[i]==array[i+1])
	            i++;
	        else{
	            printf("%d ",array[i]);
	            no_of_unpair_found++;
	            if(no_of_unpair_found==2)
	                break;
	        }
	        }
	        printf("\n");
	    T--;
	}
	return 0;    
}