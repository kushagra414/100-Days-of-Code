#include<bits/stdc++.h>
using namespace std;

struct Intervals{
    int start;
    int end;
};

bool Compare(Intervals i1,Intervals i2){
    return i1.start<i2.start;
}

vector<Intervals> Merge(Intervals interval[],int n);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    Intervals interval[N];
	    for(int i=0;i<N;i++){
	        cin>>interval[i].start;
	        cin>>interval[i].end;
	    }
	    sort(interval,interval+N,Compare);
	    
	    vector<Intervals>vec = Merge(interval,N);
	    for(auto it=vec.begin();it!=vec.end();++it){
	        Intervals inter = *it;
	        cout<<inter.start<<" ";
	        cout<<inter.end<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}


vector<Intervals> Merge(Intervals interval[],int n){
    vector<Intervals>vec;
    vec.push_back(interval[0]);
    for(int i=1;i<n;i++){
        Intervals previous = vec.back();
        vec.pop_back();
        if(previous.end>=interval[i].start){
            if(interval[i].end>previous.end)
                previous.end = interval[i].end;
            vec.push_back(previous);
        }
        else{
            vec.push_back(previous);
            vec.push_back(interval[i]);
        }
    }
    return vec;
}