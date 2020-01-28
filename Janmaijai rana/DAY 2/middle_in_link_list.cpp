
// only driver code
int getMiddle(Node *head)
{
   int n=0,i=1,p=0;
   struct Node* start=nullptr;
   struct Node* first=nullptr;
   start=head;
   first=head;
   
   while(start!=nullptr){
   n++;
   start=start->next;}
   
   while(i<=n/2){
      first=first->next;
      i++;
   }
   
     p=first->data;
   
   return p;
   
   
}




   





