#include <bits/stdc++.h>
using namespace std;

struct Activity{
    int start,end;
};

bool CompareActivity(Activity a1, Activity a2){
    return a1.end<a2.end;
}

int main() {
	int T;
	cin>>T;
	while(T){
	    int N,number_of_act=1;
	    cin>>N;
	    Activity act[N];
	    for(int i=0;i<N;i++)
	        cin>>act[i].start;
	    for(int i=0;i<N;i++)
	        cin>>act[i].end;
	    sort(act, act+N, CompareActivity);
	    int j=0;
	    for(int i =1;i<N;i++)
	        if(act[i].start>=act[j].end){
	            number_of_act++;
	            j = i;   
	        }
	    cout<<number_of_act<<endl;
	    T--;
	}
	return 0;
}