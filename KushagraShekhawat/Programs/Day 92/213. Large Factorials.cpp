#include<iostream>
using namespace std;
int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N,power=0;
	    cin>>N;
	    double fact=1;
	    for(int i=1;i<=N;i++){
	        fact*=i;
	        while(int(fact)>9){
	            power++;
	            fact/=10;
	        }
	    }
	    cout<<int(fact)<<" "<<power<<endl;
	}
	return 0;
}