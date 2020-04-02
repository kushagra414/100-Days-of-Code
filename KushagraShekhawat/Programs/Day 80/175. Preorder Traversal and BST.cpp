#include <iostream>
#include<limits.h>
using namespace std;

void checkBST(int preOrder[], int n, int minLim, int maxLim);
int index=0;
int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int preOrder[N];
	    for(int i=0;i<N;i++)
	        cin>>preOrder[i];
	    index =0;
	    checkBST(preOrder,N,INT_MIN,INT_MAX);
	    if(index==N)
	        cout<<1<<endl;
	    else
	        cout<<0<<endl;
	}
	return 0;
}

void checkBST(int preOrder[], int n, int minLim, int maxLim){
    if(index>=n)
        return;
    if(preOrder[index]<minLim or preOrder[index]>maxLim){
        return;
    }
    int val = preOrder[index++];
    checkBST(preOrder,n,minLim,val);
    checkBST(preOrder,n,val,maxLim);
}