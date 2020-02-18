}

#include <bits/stdc++.h>
using namespace std;

struct Location{
    int i;
    int j;
};

bool distinct(int a, int b, int c, int d){
    if(a!=b&&a!=c&&a!=d)
        if(b!=c&&b!=d)
            if(c!=d)
                return 1;
    return 0;
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	   int N,sum,flag=0;
	   scanf("%d%d",&N,&sum);
	   
	   int array[N];
	   for(int i=0;i<N;i++)
	        scanf("%d",&array[i]);
	        
	   sort(array,array+N);
	   
	   unordered_map <string,int> mp;
	   
	   string current="";
	   int sizeOfTwoSum = ((N-1)*N)/2;
	   int TwoSum[sizeOfTwoSum],k=0;
	   //Sum of all Pairs
	   Location L[sizeOfTwoSum];
	   for(int i=0;i<N;i++)
	        for(int j=i+1;j<N;j++){
	            TwoSum[k]=array[i]+array[j];
                //printf("TwoSum[k++]:%d\n",TwoSum[k]);
	            L[k].i=i;
	            L[k].j=j;
                k++;
	        }
	        
       int a,b,c,d; 
	   for(int i=0;i<sizeOfTwoSum;i++)
            for(int j=i+1;j<sizeOfTwoSum;j++){
                if(TwoSum[i]+TwoSum[j]==sum){
                    a=L[i].i, b=L[i].j, c=L[j].i, d=L[j].j;
                    int temp[] = {array[L[i].i], array[L[i].j], array[L[j].i], array[L[j].j]};
                    sort(temp,temp+4);
                    current = to_string(temp[0])+to_string(temp[1])+to_string(temp[2])+to_string(temp[3]);
                    if(mp[current]==0&&distinct(a,b,c,d)){
                            printf("%d %d %d %d $",temp[0],temp[1],temp[2],temp[3]);
                            mp[current]++;
                            flag=1;
                    }
                }
	   }
	if(flag==0)
	    printf("-1");
    printf("\n");
	}
	return 0;
}