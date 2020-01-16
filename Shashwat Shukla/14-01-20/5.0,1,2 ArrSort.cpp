#include<conio.h>
#include<stdio.h>

main(){
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int p=0,q=0,r=0;
		scanf("%d",&n);int a[n];
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
			if(a[j]==0)
			p++;
			else if(a[j]==1)
			q++;
			else
			r++;
		}
		for(int j=0;j<n;j++)
		{
			if(j<p)
			a[j]=0;
			else if(j<p+q)
			a[j]=1;
			else
			a[j]=2;
		}
		for(int j=0;j<n;j++)
		{
			printf("%d ",a[j]);
	    }
	    printf("\n");
	}
}
