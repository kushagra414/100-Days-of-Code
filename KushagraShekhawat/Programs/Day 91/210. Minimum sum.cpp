#include<bits/stdc++.h>
using namespace std;

string findSum(string num1, string num2);

int main()
 {
	int T;
	cin>>T;
	while(T--){
	    int N;
	    cin>>N;
	    bool oddEven=0;
	    int arr[N],i,j;
	    int hash[10]={0};
	    for(int i=0;i<N;i++){
	        cin>>arr[i];
	        hash[arr[i]]++;
	    }
	    
	    string num1,num2;
	    for(int i=0;i<10;){
	        if(hash[i]==0){
	            i++;
	            continue;
	        }
	        if(oddEven==1){
	            num1+=to_string(i);
	            hash[i]--;
	            oddEven=0;
	        }
	        else{
	            num2+=to_string(i);
	            hash[i]--;
	            oddEven=1;
	        }
	    }
	    cout<<findSum(num1,num2)<<endl;
	}
	return 0;
}

string findSum(string num1, string num2){
    
    int carry=0;
    int len = num2.length();
    string sum;
    if(num2.length()>num1.length())
        num1.insert(0,"0");
    for(int i=len-1;i>=0;i--){
        int x=num1[i]-48;
        int y=num2[i]-48;
        int temp = x+y+carry;
        int z = temp%10;
        sum+=to_string(z);
        carry = temp/10;
    }
    if(carry!=0)
        sum+=to_string(carry);
    int i=len;
    while(sum[i-1]-48==0){
        sum.erase(i-1,i);
        i--;
    }
    reverse(sum.begin(),sum.end());
    
    return sum;
}