#include <bits/stdc++.h>
using namespace std;

void printPreOrder(int pre[],int N, int minVal, int maxVal, int &preIndex);

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    cin>>N;
	    int array[N];
	    for(int i=0;i<N;i++)
	        cin>>array[i];
	    int index = 0;
	    printPreOrder(array,N, INT_MIN, INT_MAX, index);
	    cout<<endl;
	}
	return 0;
}

void printPreOrder(int pre[],int N, int minVal, int maxVal, int &preIndex){
    if(preIndex==N)
        return;
    
    if(pre[preIndex]<minVal or pre[preIndex]>maxVal)
        return;
    
    int val = pre[preIndex++];
    
    printPreOrder(pre, N, minVal, val, preIndex);
    printPreOrder(pre, N, val, maxVal, preIndex);
    cout<<val<<" ";
}