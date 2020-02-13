#include <bits/stdc++.h>
using namespace std;

long long largestPrimeFactor(long long num){
    long long maxprime=0;
    int i;
    while(num%2 == 0){
        maxprime=2;
        num=num/2;
    }
    for(i=3;i<=sqrt(num);i=i+2){
        while(num%i==0){
            maxprime=i;
            num=num/i;
        }
    }
    if(num>2){
        maxprime=num;
    }
    return maxprime;
}

int main() {
    int T;
    cin>>T;
    while(T--){
        long long num;
        cin>>num;
        cout<<largestPrimeFactor(num)<<endl;
    }
	return 0;
}
