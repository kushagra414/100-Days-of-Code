#include <iostream>
#include <string>
using namespace std;

int main(){
    int t=0;

    //cout<<"enter the number of test cases "<<endl;
    cin>>t;
    while(t){
        string str;
      //  cout<<"enter the string "<<endl;
        cin>>str;
        int p=0;
        p=str.length();

        int left=0,right=0,length=0,max_length=0;

        //left to right scanning of string

        for(int i=0;i<p;i++){

               if(right>left){
                left=0;
                 right=0;}

            if(str[i]=='(')
                left++;

            if(str[i]==')')
                right++;

            if(left==right)
                length=left+right;

            if(length>max_length)
                max_length=length;
        }

        // right to left scanning of string

        int left1=0,right1=0;

        for(int i=p-1;i>=0;i--){

                if(left1>right1){
                left1=0;
                right1=0;}

              if(str[i]=='(')
                    left1++;

              if(str[i]==')')
                right1++;

              if(left1==right1)
                length=left1+right1;

              if(length>max_length)
                max_length=length;

        }


       // cout<<" maximum length is "<<endl;
        cout<<max_length<<endl;


t--;
    }
}


