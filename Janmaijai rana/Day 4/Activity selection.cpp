#include <iostream>
#include <algorithm>
using namespace std;

struct Activity{
int start,end;
};

bool arraysort(Activity a,Activity b){
   return(a.end<=b.end);}

int main(){
    int t=0,n=0;
//cout<<"enter the number of test cases "<<endl;
cin>>t;
while(t){
   // cout<<" enter the size of array "<<endl;
    cin>>n;
    Activity arr[n];

   // cout<<" enter starting time "<<endl;
    for(int i=0;i<n;i++)
       cin>>arr[i].start;

    //cout<<" enter end time "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i].end;

    sort(arr,arr+n,arraysort); //call to function arraysort
      int count=1; //1st pair is always choosen
      int f=0;
      for(int k=1;k<n;k++)
      {
          if(arr[f].end<=arr[k].start){
            count++;
            f=k;
          }
      }

     // cout<<" maximum number of activities "<<endl;
      cout<<count<<endl;



 t--;
}
}
