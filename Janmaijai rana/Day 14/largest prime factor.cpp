#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int t=0;
  cin>>t;
  while(t){
      int n;
      cin>>n;
      
      while(n%2==0)
         n=n/2;

 //Every composite number has at least 
//one prime factor less than or equal to square root of itself.  
     
      for(int i=3;i<=sqrt(n);i=i+2){
          while(n%i==0)
            n=n/i; }
   
      if(n>2)
       cout<<n<<endl;

  t--;
  }
	return 0;
}
