
int main() {
	int T;
	scanf("%d",&T);
	while(T--){
	    int N;
	    scanf("%d",&N);
	    int array[N];
	    int sum=0;
	    for(int i=0;i<N;i++){
	        scanf("%d",&array[i]);
	        sum+=array[i];
	    }
	    int hash[N+1];
	    int repeatedNo,missingNo;
	    memset(hash,0,(N+1)*sizeof(int));
	    for(int i=0;i<N;i++){
	        hash[array[i]]++;
	        if(hash[array[i]]>1)
	            repeatedNo=array[i];
	    }
	    for(int i=1;i<N+1;i++)
	        if(hash[i]==0){
	            missingNo=i;
	            break;
	        }
	   printf("%d %d\n",repeatedNo,missingNo);
	            
	    
	}
	return 0;
}
