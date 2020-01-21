    for(int i=1,j=n-1;i<=j;){

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void TwoPointer(int hash[],int n,int x);

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,x;
	    scanf("%d",&N);
	    scanf("%d",&x);
	    int array[N];
    	for(int i=0;i<N;i++){
    	    scanf("%d",&array[i]);
    	}
        sort(array, array+N);
    	/*int hash[max_ele+1];
    	memset(hash,0,(max_ele+1)*sizeof(int));
    	for(int i=0;i<N;i++)
    	    hash[array[i]]=array[i];*/
    	TwoPointer(array,N,x);
	}
	return 0;
}

void TwoPointer(int hash[],int n,int x){
    bool found_sum = 0;
    for(int i=0,j=n-1;i<j;){
        //printf("hash[%d] : %d, hash[%d] : %d\n",i,hash[i],j,hash[j]);
        /*if(hash[i]==0 || hash[j]==0)
            if(hash[i]==0)
                i++;
            else
                j--;*/
        if(hash[i]+hash[j]>x)
            j--;
        else if(hash[i]+hash[j]<x)
            i++;
        else if(hash[i]+hash[j]==x){
            printf("Yes\n");
            found_sum=1;
            break;
        }
    }
    if(found_sum==0)
        printf("No\n");
}
