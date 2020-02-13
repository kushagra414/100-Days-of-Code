#include<iostream>
using namespace std;

void printpreorder(int arr[],int low,int high){
    if(low>high){
        return ;
    }
    int mid=(low+((high-low)/2));
    cout<<arr[mid]<<" ";
    printpreorder(arr,low,mid-1);
    printpreorder(arr,mid+1,high);
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int A[N];
        for(int i =0;i<N;i++){
            cin>>A[i];
        }
    printpreorder(A,0,N-1);
    cout<<endl;
    }
    return 0;
}
