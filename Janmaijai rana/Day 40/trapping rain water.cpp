#include <iostream>
using namespace std;

int main() {
    int t=0;
    cin>>t;
	while(t){
	int n=0,sum=0;
	cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
     
      int left[n],right[n];
     int max=arr[0];
     
     for(int i=0;i<n;i++)
      {
       if(max<arr[i])
           max=arr[i];
       left[i]=max;          
         }

      int max1=arr[n-1];
      
       for(int i=n-1;i>=0;i--)
      {
       if(max1<arr[i])
           max1=arr[i];
       right[i]=max1;          
         }

      int min=0;
      
      for(int i=0;i<n;i++){
          if(left[i]<right[i])
             min=left[i];
          else
             min=right[i];
       sum+=(min-arr[i]);         
      }
   
    cout<<sum;
    cout<<endl;
	t--;
	}
	return 0;
}
