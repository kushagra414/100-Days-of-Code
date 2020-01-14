#include <stdio.h>

int main() {
	//code
	int n,t;
	scanf("%d",&t);
	for (int j=0; j<t; j++)
	{
		int s=0,sum=0 ;
	    scanf( " %d ", &n ); int a[n-1];
	    for( int i=0; i < n-1; i++ )
	    {scanf( "%d", &a[i] ) ; s = s + a [ i ]; }
	    sum = ( n ) * ( 1 +n ) /2 ; // printf ("%d %d",s,sum) ; 
	    printf ( "%d\n", sum - s ) ;
	}
	return 0;
}
