#include<iostream>
using namespace std;
void array_init(int N,int A[])
{
    for(int i=0;i<N-1;i++)
    {
        cin>>A[i];
    }
}
void missing(int N,int A[])
{
    int S=0,sum=0,result;
    for(int i=1;i<=N;i++)
        S = S + i;

    for(int i=0;i<N-1;i++)
        sum = sum+A[i];

    result = S-sum;
    cout<<result<<"\n";

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int A[N];
        array_init(N,A);
        missing(N,A);
    }
}
