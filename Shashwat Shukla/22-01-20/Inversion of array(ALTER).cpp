#include<stdio.h>

int merge_sort(int x[],int y,int z,int c);
int merge(int s[],int t,int u,int c) ;
int main()
{
	int t; scanf("%d",&t);
	for(int g=0;g<t;g++)
	{
	int l,f=0,o , c=0 ; 
	//User enters length of Array//
	printf("Enter the Length of Array:\n");
	scanf("%d",&l);
	int a[l];
	for(o=0;o<l;o++)
	{
		printf("Enter a Number\n");
		scanf("%d",&a[o]);
	}
	//Checks if there are more than 1 elements //
	 c = merge_sort(a,f,l,c);
	if(c!=0)
	  printf("%d",c); 
	else
	printf("0");
	}
}
int merge_sort(int x[],int y,int z,int c)
{
	if((y+z)/2!=y)
	{
		//First Half//
	c=	merge_sort(x,y,(y+z)/2 , c);
		//Second Half//
	c=	merge_sort(x,(y+z)/2+1,z,c);
	}
	else
	{
		//When only 1 element is left we merge//
		c = merge(x,y,z ,c);
	}
	return c;
}
int merge(int s[],int t,int u,int c)
{
	int i=0,j=0,d=0;
	for(i=0;i<t-1;i++)
	{
		for(j=i;j<u+1;j++)
		{
			if(s[i]>s[j])
			{
	         d=s[i];
 	         s[i]=s[j];
 	         s[j]=d;
 	         c++;
			}
		}
	}
	return c;
}
