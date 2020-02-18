#include<iostream>
#include <math.h>
using namespace std;

bool check(int t,int n){
if(t>=0 && t<=200 && n>=1 && n<=pow(10,7))
    return true;
return false;
}


int main(){
int t=0,n=0;
//cout<<"enter the number of test cases "<<endl;
cin>>t;
while(t>0){
       // cout<<"enter the size of the array "<<endl;
        cin>>n;
        if(check(t,n)){
         int arr[n],sum=0;
    //cout<<"enter array elements "<<endl;
 for(int i=0;i<n-1;i++)
    cin>>arr[i];
   sum=(n*(n+1))/2;
 for(int i=0;i<n-1;i++)
    sum=sum-arr[i];
 cout<<sum<<endl;
     t--;
}}
}
