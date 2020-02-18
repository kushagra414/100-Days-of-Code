#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int ArrivalTime[N],DepartureTime[N];
	    for(int i=0;i<2*N;i++)
	        if(i<N)
	            scanf("%d",&ArrivalTime[i]);
	        else
	            scanf("%d",&DepartureTime[i-N]);
	    sort(ArrivalTime,ArrivalTime+N);
	    sort(DepartureTime,DepartureTime+N);
	    
	    int NoOfTrainsOnPlt=0,DepTime,minPlt=1;
	    for(int i=0,j=0;i<N&&j<N;){
	        if(ArrivalTime[i]<=DepartureTime[j]){
	            NoOfTrainsOnPlt++;
	            i++;
	        }
	        else if(ArrivalTime[i]>DepartureTime[j]){
	            NoOfTrainsOnPlt--;
	            j++;
	        }
	        if(minPlt<NoOfTrainsOnPlt)
	            minPlt=NoOfTrainsOnPlt;
	        }
	   printf("%d\n",minPlt); 
	    }
	    return 0;
	}