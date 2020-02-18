#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void FindEquilibruim(int array[], int n);

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int n;
	    scanf("%d",&n);
	    int array[n];
	    for(int i=0;i<n;i++)
	        scanf("%d",&array[i]);
	    //sort(array,array+n);
	    if(n>1)
	        FindEquilibruim(array,n);
	    else
	        printf("%d\n",1);
	}
	return 0;
}

void FindEquilibruim(int array[], int n){
    int left_sum=array[0],right_sum=array[n-1];
    bool found_equilibruim=0;
    for(int i=1,j=n-2;i<=j;){
            //printf("left_sum :%d, right_sum :%d and i =%d, j=%d\n",left_sum,right_sum,i,j);
        if(left_sum<right_sum)
            left_sum+=array[i++];
        else if(left_sum>right_sum)
                right_sum +=array[j--];
        else if(left_sum==right_sum&&i==j){
            printf("%d\n",i+1);
            found_equilibruim=1;
            break;
        }
        else if(left_sum==right_sum&&i!=j){
            left_sum+=array[i++];
            right_sum+=array[j--];
        }
    }
    if(!found_equilibruim)
        printf("-1\n");
}
