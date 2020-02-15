#include <bits/stdc++.h>
using namespace std;

int min_platform(int A[],int D[],int N){
    int i=1,j=0,platform_needed=1,min=1;
    sort(A,A+N);
    sort(D,D+N);
    while(i<N && j<N){
        if(A[i]<=D[j]){
            platform_needed++;
            i++;
            if(platform_needed>min){
                min=platform_needed;
            }
        }
        else if(A[i]>D[j]){
            platform_needed--;
            j++;
        }
    }
    return min;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int N,i=0;
        cin>>N;
        int A[N],D[N];
        for(i=0;i<N;i++){
            cin>>A[i];
        }
        for(i=0;i<N;i++){
            cin>>D[i];
        }
        int answer=min_platform(A,D,N);
        cout<<answer<<endl;
        
    }
	return 0;
}
