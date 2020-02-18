// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    int i=0,j=0,max=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[i].first>p[j].first){
                val temp= p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    int lis[n];
    for(i=0;i<n;i++){
        lis[i]=1;
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(p[i].first>p[j].second && lis[i]<=lis[j]){
                lis[i]=lis[j]+1;
            }
        }
    }
    max=lis[0];
    for(i=0;i<n;i++){
        if(max<lis[i]){
            max=lis[i];
        }
    }
    return max;
}
