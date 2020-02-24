#include <bits/stdc++.h>
using namespace std;

int findMissing(int *arr,int max,int N){
    if(max<=0)
        return 1;
    if(max<N)
        max=N-1;
    int hash[max+1];
    memset(hash,-1,(max+1)*sizeof(int));
    for(int i=0;i<N;i++){
        if(arr[i]>0)
            hash[arr[i]]=arr[i];
    }
    for(int i=1;i<max+1;i++){
        if(hash[i]==-1)
            return i;
    }
    return N+1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int array[N],max=INT_MIN;
	    for(int i=0;i<N;i++){
	        cin>>array[i];
	        if(array[i]>max)
	            max=array[i];
	    }
	    int missing = findMissing(array,max,N);
	    printf("%d\n",missing);
	}
	return 0;
}
