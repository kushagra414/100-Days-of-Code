#include <stdio.h>
#include <string.h>

void RemoveDuplicates(char array[], int start);
void Test(char array[]);

int main() {
	int T;
	scanf("%d",&T);
	while(T){
	    char array[50],range,count=0;
	    scanf("%s",array);
        Test(array);
	    printf("%s\n",array);
	    T--;
    }
	return 0;
}

void RemoveDuplicates(char array[], int start){
    int i = start,count=0;
    char repeated = array[start];
    while(array[i]==repeated){
        count++;
        i++;
    }
    int len = strlen(array) - start+count;
    i=0;
    while(len){
        array[start+i] = array[start+count];
        count++;
        i++;
        len--;
    }
}
void Test(char array[]){
    int no_repeatation = 0;
    for(int i=0;i<strlen(array);i++){
	if(array[i]==array[i+1]){
	    RemoveDuplicates(array, i);
        i--;
        no_repeatation = 1;
	    }
    }
    while(no_repeatation){
        Test(array);
        no_repeatation=0;
    }
}