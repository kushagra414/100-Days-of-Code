#include <stdio.h>
int main() 
{
 
int T,N;
scanf("%d",&T);
for(int i=0;i<T;i++)
{
 scanf("%d",&N);
 int t=0;
 
 int total=0;
 int C[N-1];
 for(int i=0;i<N-1;i++)

 {
 scanf("%d",&C[i]);
    t = t+C[i];
 }
    total = (N)* (1 + N) / 2; 
    	
        
       total= total-t;
    printf("%d\n",total); 
}
return 0;
} 
