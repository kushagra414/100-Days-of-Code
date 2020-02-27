// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends
/*You are required to complete this method*/

int MaxArea=-1;

void FindMaxArea(int N, int *hist){
    stack<int>s;
    int area=0,ele=0,i=0;
	    for(i=0;i<N;i++){
	        if(s.empty()||hist[i]>hist[s.top()])
	            s.push(i);
	        else{
	               while(!s.empty()&&hist[s.top()]>hist[i]){
	                   ele=s.top();
	                   s.pop();
	                    if(s.empty())
	                        area=hist[ele]*i;
	                    else
	                        area=hist[ele]*(i-s.top()-1);
	                    if(MaxArea<area)
	                        MaxArea=area;
	                }
	           s.push(i);
	            }
	       }
	       while(!s.empty()){
	           ele=s.top();
	           s.pop();
	           if(s.empty())
	               area=hist[ele]*i;
	           else
	               area=hist[ele]*(i-s.top()-1);
	           if(MaxArea<area)
	               MaxArea=area;
	    }
}

int maxArea(int M[MAX][MAX], int n, int m) {
    int hist[m];MaxArea=-1;
    memset(hist,0,sizeof(int)*m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]==0)
                hist[j]=0;
            else
                hist[j]+=1;
        }
        //Find Max of Histogram
        FindMaxArea(m,hist);
    }
    return MaxArea;
}
