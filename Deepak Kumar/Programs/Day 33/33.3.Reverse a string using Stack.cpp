// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        reverse(str,len);
        cout<<str;
        cout<<endl;
    }
        return 0;
}
// } Driver Code Ends
void reverse(char *str, int len)
{
    int i=0,j=0;
    for(i=0,j=len-1;i<len/2;i++,j--){
        int temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}
