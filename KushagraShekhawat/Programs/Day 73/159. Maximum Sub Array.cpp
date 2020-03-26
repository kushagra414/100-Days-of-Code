 
#include <bits/stdc++.h>
using namespace std;

struct Sum{
    int start;
    int end;
    Sum(int i, int j){
        start = i;
        end = j;
    }
};


int MaxSubArray(int arr[], int N);
int findMaxSum(int arr[], int N);

int main() {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	        cin>>arr[i];
	    MaxSubArray(arr, N);
	    cout<<endl;
	}
	return 0;
}

int findMaxSum(int arr[], int N){
    int maxSum=0,sum=0;
    for(int i=0;i<N;i++){
        if(arr[i]>=0)
            sum+=arr[i];
        else{
            maxSum = sum>maxSum?sum:maxSum;
            sum=0;
        }
    }
    return sum>maxSum?sum:maxSum;
}

bool collision(Sum const &s1, Sum const &s2){
    int tempLen = s1.end-s1.start;
    int sumLen = s2.end-s2.start;
    if(tempLen<sumLen)
        return 1;
    return 0;
}

int MaxSubArray(int arr[], int N){
    int sum=0,start=0,max=0,maxSum=findMaxSum(arr,N)+1;
    Sum hash[maxSum]=Sum(-1,-1);
    for(int i=0;i<N;i++){
        if(arr[i]>=0){
            sum+=arr[i];
            if(i==N-1){
                if(hash[sum].start==-1 and hash[sum].end==-1)
                    hash[sum]=Sum(start,i+1);
                else if(collision(hash[sum], Sum(start,i+1)))
                        hash[sum]=Sum(start,i+1);
            }
        }
        else{
            if(hash[sum].start==-1 and hash[sum].end==-1)
                hash[sum]=Sum(start,i);
            else if(collision(hash[sum], Sum(start,i)))
                    hash[sum]=Sum(start,i);
            start=i+1;
            sum=0;
        }
    }
    Sum SubArray = Sum(-1,-1);
    for(int i=maxSum-1;i>=0;i--){
        if(hash[i].start!=-1){
            SubArray = hash[i];
            break;
        }
    }
    for(int i=SubArray.start;i<SubArray.end;i++)
        cout<<arr[i]<<" ";
}
