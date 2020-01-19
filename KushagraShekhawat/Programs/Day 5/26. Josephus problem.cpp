// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int josephus(int n, int k);

int main() {

	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<josephus(n,k)<<endl;
	}
	return 0;
}// } Driver Code Ends
/*You are required to complete this method */
int josephus(int n, int k)
{
   int array[n];
   for(int i=0;i<n;i++)
        array[i] = i;
   int kill = n-1,i=0;
   k = k-1;
   while(kill){
       i=i+k;
       if(i>=n){
           i = i%n;
           //printf("i%n = %d\n",i);
       }
           //printf("");
       array[i] = -1; //killed
       kill--;
       for(int j=i;j<n-1;j++)
            array[j] = array[j+1];
       n = n-1;
       //i--;
       //printf("Killed %d\n",(i)%n);
       /*for(int j=0;j<n;j++)
            printf("%d ",array[j]);
       printf("\n");*/
   }
   return array[0]+1;
}
