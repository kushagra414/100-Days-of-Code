#include <iostream>
using namespace std;

int main() {
    int t=0;
  //cout<<"enter number of test cases "<<endl;
  cin>>t;
   while(t){
       int n,sum=0;
      // cout<<"enter the size of array "<<endl;
       cin>>n;
       int arr[n];
          for(int i=0;i<n;i++)
           cin>>arr[i];

        for(int i=0;i<n;i++)
           sum+=arr[i];

        int flag=0;
       int k=0,p=0;
       if(n==1){
        cout<<1<<endl;
        flag=1;}
       else{
       for(int i=0;i<n;i++){
           k+=arr[i];
          // cout<<" k value "<<k<<endl;
           p=k-arr[i];
           // cout<<" p value "<<p<<endl;
           sum=sum-arr[i];
     //cout<<" sum value "<<sum<<endl;
           if(sum==p){
           cout<<i+1<<endl;
           flag=1;}
           }
        }
       if(flag==0)
       cout<<"-1"<<endl;

       t--;
          }

	return 0;
}
