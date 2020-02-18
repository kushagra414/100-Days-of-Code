#include <iostream>
using namespace std;

int main() {
int t=0;
cin>>t;
while(t){
    int n,X,flag=0;
    cin>>n>>X;
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
     
     int p=0;
     for(int k=0;k<n;k++){
         p=k+1;
     for(int m=p;m<n;m++){
         if(a[k]+a[m]==X && flag==0){
           cout<<"Yes"<<endl;
           flag=1;}
        }
        if(flag==1)
        break;
       }
     if(flag==0)
      cout<<"No"<<endl;
t--;    
}

}
