#include <bits/stdc++.h>
using namespace std;
int main(){
    int t=0;
    cin>>t;
    while(t){
      int n=0;
      cin>>n;
      int arr[n];
      for(int i=0;i<n;i++)
        cin>>arr[i];
    int flag=0;
    cout<<-1<<" ";    
     for(int i=1;i<n;i++){    
         
          for(int j=i-1;j>=0;j--){
                if(arr[i]>arr[j]){
                   cout<<arr[j]<<" ";
                   flag=1;
                   break;
                }
             }
           if(flag!=1)
            cout<<-1<<" ";
        flag=0;    
     }
    cout<<endl;
    t--;}
    return 0;
}