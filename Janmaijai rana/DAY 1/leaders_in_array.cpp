#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int main()
{
   int t=0,n=0;
//cout<<"enter the number of test cases "<<endl;
    cin>>t;
    stack <int> s;
    while(t>0){
       // cout<<"enter the size of the array "<<endl;
        cin>>n;
        
       int arr[n];
       for(int i=0;i<n;i++)
        cin>>arr[i];

    int MAX=arr[n-1];


  for(int i=n-1;i>=0;i--)
    {
    if(i==n-1){
      s.push(MAX);}

    if(i<(n-1) && arr[i]>=MAX){
            MAX=arr[i];
            s.push(MAX);}
    }

   while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();}
    cout<<endl;

t--;
}
}
