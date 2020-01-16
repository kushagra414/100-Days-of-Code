#include <iostream>
using namespace std;


int main(){
int t=0,n=0;
//cout<<"enter test cases "<<endl;
cin>>t;
while(t){
    //cout<<"enter the array size "<<endl;
    cin>>n;
    int arr[n];
    int count0=0,count1=0,count2=0;

    for(int i=0;i<n;i++)
        cin>>arr[i];
        

    for(int k=0;k<n;k++){
            if(arr[k]==0)
            count0++;
            if(arr[k]==1)
             count1++;
            if(arr[k]==2)
             count2++;
    }
    int f=0;

    while(count0){
      arr[f]=0;
      f++;
      count0--;}

    while(count1){
        arr[f]=1;
        f++;
        count1--;
    }
    while(count2){
        arr[f]=2;
        f++;
        count2--;
    }
    
    
    

    for(int z=0;z<n;z++)
        cout<<arr[z]<<" ";
        
    cout<<endl;


    t--;
}
}
