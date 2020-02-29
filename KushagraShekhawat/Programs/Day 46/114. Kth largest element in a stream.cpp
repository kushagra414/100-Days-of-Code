#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{
    int k,n;
    cin>>k>>n;
    int i =0;
    int num;
priority_queue <int , vector<int> , greater<int>> pq;
while(i<n)
{
   cin>>num;
   if(pq.size()<k)
  { pq.push(num);
  if(pq.size()==k)
  cout<<pq.top()<<" ";
  else
      cout<<"-1 ";
  }
   else if(pq.size()==k && num>pq.top())
 {   
 pq.pop();
     pq.push(num);
     cout<<pq.top()<<" ";
     
 }
 else if(pq.size()==k && num<=pq.top())
 {
     cout<<pq.top()<<" ";
 }
   
   i++;
}
cout<<endl;
    
}
}