#include <bits/stdc++.h>
using namespace std;

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
	   string repeated="",current="";
	   for(int i=0;i<N;i++)
	        for(int j=i+1;j<N;j++)
	            for(int k=j+1;k<N;k++)
	                for(int l=k+1;l<N;l++)
	                    if(array[i]+array[j]+array[k]+array[l]==sum){
	                        current = to_string(array[i])+to_string(array[j])+to_string(array[k])+to_string(array[l]);
	                        if(mp[current]==0){
	                        printf("%d %d %d %d $",array[i],array[j],array[k],array[l]);
	                        mp[current]++;
	                        flag=1;
	                        }
	                    }
	if(flag==0)
	    printf("-1");
    printf("\n");
	}
	return 0;
}