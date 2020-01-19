#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    if(N%2==0){
	        if(N ==2)
	            printf("No\n");
	        else
	            printf("Yes\n");
	    }
	    else if(N==3){
	       printf("No\n");
	    }
	    else{
	        N=N-2;
	        bool prime[N+1];
	        memset(prime,true,sizeof(prime));
	        for(int p=2;p*p<=N;p++){
	            if(prime[p]==true){
	                for(int i=p*p;i<=N;i=i+p)
	                    prime[i] = false;
	            }
	        }
	    if(prime[N])
	        printf("Yes\n");
	    else
	        printf("No\n");
	    }
	}
	return 0;
}
