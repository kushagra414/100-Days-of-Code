#include<stdio.h>
#include<conio.h>

main()
{
	int t;
	scanf("%d",&t);
	for(int i = 0;i<t;i++)
	{
		int n,s,su=0 ,j,k ,f=0;
		scanf("%d %d",&n,&s);
		int a[n];
		for(j = 0; j<n ; j++ )
		{
			scanf("%d",&a[j]);
		}
		
		for(j=0 ; j<n ; j++)
		{
			su=0;
			for(k=j ; k<n ;k++)
			{
			su = su+a[k];
			  if(su==s)
			  {
			    printf("%d %d\n",(j+1),(k+1)); f=1;
			    break; 
			  }
			  if(su>s)
			  break;
		    }
			if(f==1)
			break;   
	    }
	    if(f==0)
		printf("%d\n",-1);
	}
	getch();
}
