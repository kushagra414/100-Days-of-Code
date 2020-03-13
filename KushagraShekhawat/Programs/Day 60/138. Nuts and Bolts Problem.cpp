#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int Nuts[35],Bolts[35],N,add=0;
        char chr;
	    cin>>N;
	    memset(Nuts,0,35*sizeof(int));
	    memset(Bolts,0,35*sizeof(int));
	    for(int i=0;i<N;i++){
	        cin>>chr;
	        if(chr=='^')
	            Nuts[33]++;
	        else if(chr=='~')
	            Nuts[34]++;
	        else if(chr != ' ')
	            Nuts[chr-33]++;
	    }
	    for(int i=0;i<N;i++){
	        cin>>chr;
	        if(char(chr)=='^')
	            Bolts[33]++;
	        else if(char(chr)=='~')
	            Bolts[34]++;
	        else
	            Bolts[chr-33]++;
	    }
	    for(int i=0;i<35;i++){
	        if(Nuts[i] >0){
	            if(i==33)
	                add = 94-33;
	            else if(i==34)
	                add = 126-34;
	            else
	                add = 33;
    	        while(Nuts[i]--){
    	            cout<<char(i+add)<<" ";
    	            }
	        }
	    }
        cout<<endl;
        for(int i=0;i<35;i++){
	        if(Bolts[i] >0){
	            if(i==33)
	                add = 94-33;
	            else if(i==34)
	                add = 126-34;
	            else
	                add = 33;
    	        while(Bolts[i]--){
    	            cout<<char(i+add)<<" ";
    	            }
	        }
	    }
	    cout<<endl;
	}
	return 0;
}