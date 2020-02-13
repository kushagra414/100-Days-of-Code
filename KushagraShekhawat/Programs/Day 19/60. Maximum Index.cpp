#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void maxIndexDiff(int array[], int N);

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int array[N];
	    for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);
	    maxIndexDiff(array,N);
	}
	return 0;
}

void maxIndexDiff(int array[], int N){
    int LMin[N],RMax[N],maxDiff=0;

    LMin[0] = array[0];
    for(int i=1;i<N;i++)
        LMin[i] = min(array[i],LMin[i-1]);

    RMax[N-1] = array[N-1];
    for(int j=N-2;j>=0;j--)
        RMax[j] = max(array[j],RMax[j+1]);

    for(int i=0,j=0;i<N&&j<N;){
        if(LMin[i]<=RMax[j]){
            maxDiff = max(maxDiff, j-i);
            j++;
        }
        else
            i++;
    }

    printf("%d\n",maxDiff);
}
