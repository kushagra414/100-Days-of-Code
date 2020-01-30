#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Sort{
    int element;
    int frequency;
    Sort(){
    element=0;
    frequency=0;
    }
};

bool Compare(Sort array1, Sort array2){
    printf("Array 1: %d and Array2 : %d\n",array1.element,array2.element);
    if(array1.frequency==array2.frequency)
        return (array1.element<array2.element);
    return (array1.frequency>array2.frequency);
    /*else if(array1.frequency==array2.frequency)
        return array1.element<array2.element;*/
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N,var;
	    scanf("%d",&N);
	    Sort array[61];
	    for(int i=0;i<N;i++){
	        scanf("%d",&var);
	        array[var].element=var;
	        array[var].frequency++;
	    }
	    sort(array,array+61,Compare);
        for(int i=0;i<61;i++)
            while(array[i].frequency--)
                printf("%d ",array[i].element);
	   printf("\n");
	    /*for(int i=0;i<61;i++){
	        if(array[i].element!=0)
	            while(array[i].frequency--){
	        printf("%d ",array[i].element);
	            }
	    }*/
	}
	return 0;
}
