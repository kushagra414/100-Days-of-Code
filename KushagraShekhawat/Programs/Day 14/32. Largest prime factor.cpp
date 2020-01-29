#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    long long int N,HighestPrimeFactor=1;
	    scanf("%lld",&N);
	    
	    while(N%2==0){
	        N=N/2;
	        HighestPrimeFactor=2;
	    }
	    for(int i=3;i<=sqrt(N);i=i+2){
	        if(N%i==0)
	            HighestPrimeFactor=i;
	        while(N%i==0)
	            N/=i;
	    }
	    
	    if(N>2)
	        HighestPrimeFactor=N;

	    if(HighestPrimeFactor>1)
	        printf("%lld\n",HighestPrimeFactor);
	    else
	        printf("%lld\n",N);
	}
	return 0;
}