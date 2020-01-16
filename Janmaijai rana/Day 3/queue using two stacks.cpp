/* The method push to push element into the queue */
void StackQueue :: push(int x)
 {
         s1.push(x);
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
     int p=0,k=0;
     
     if(s1.empty() && s2.empty())
     return -1;
     else if(s2.empty()){
    while(!s1.empty()){
        p=s1.top();
        s2.push(p);
        s1.pop();
    }}
    
        k=s2.top();
        s2.pop();
        return k;
    
       
       
}
