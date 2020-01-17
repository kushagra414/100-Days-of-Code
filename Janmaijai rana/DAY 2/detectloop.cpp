
int detectloop(Node *head) {
    
    //using hare turtle theorem!!
    
    struct Node* hare=nullptr;
    struct Node* turtle=nullptr;
    hare=head;
    turtle=head;
    turtle=turtle->next;
        hare=(hare->next)->next;
    
    do{
        if(hare==turtle)
         break;
         
        turtle=turtle->next;
        hare=(hare->next)->next;
        
    }while(hare && hare->next);
    
    if(hare==turtle)
     return 1;
    else
       return 0;
     
