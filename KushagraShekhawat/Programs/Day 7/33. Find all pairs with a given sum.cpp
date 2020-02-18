#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void TwoPointer(int hash1[],int hash2[],int x,int n1,int n2);

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N1,N2,x;
	    scanf("%d",&N1);
	    scanf("%d",&N2);
	    scanf("%d",&x);
	    int array1[N1],array2[N2],max_ele1=0,max_ele2=0;
	    //Insert array1
	    for(int i=0;i<N1;i++){
	       scanf("%d",&array1[i]);
	       if(max_ele1<array1[i])
	           max_ele1 = array1[i];
	    }
	    //Insert array2
	   for(int i=0;i<N2;i++){
	        scanf("%d",&array2[i]);
	        if(max_ele2<array2[i])
	            max_ele2 = array2[i];
	   }
    sort(array1,array1+N1);
    sort(array2,array2+N2);
	TwoPointer(array1,array2,x,N1,N2);
	}
	return 0;
}

void TwoPointer(int hash1[],int hash2[],int x,int n1,int n2){
    bool pair_found = 0,flag=0;
    for(int i=0,j=n2-1; i<n1,j>=0; ){
            if(j<0 || i >=n1)
            return;
        if(hash1[i]+hash2[j]>x)
            j--;
        else if(hash1[i]+hash2[j]<x)
            i++;
        else{
            if(flag==0){
                printf("%d %d",hash1[i],hash2[j]);
                flag=1;
            }
            else{
                printf(", %d %d",hash1[i],hash2[j]);
            }
            i++,j--;
            pair_found = 1;
        }
    }
    if(pair_found == 0)
        printf("-1\n");
    else
        printf("\n");
}
