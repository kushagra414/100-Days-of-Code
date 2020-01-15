#include <stack>

// Should reverse list and return new head.
Node* reverseList(Node *head)
{
    stack <int> s;
    struct Node* start=nullptr;
    struct Node* first=nullptr;
    start=head;
    first=head;
    
    while(start!=nullptr){
    s.push(start->data);
    start=start->next;}
    
    while(first!=nullptr){
    first->data=s.top();
    s.pop();
    first=first->next;}
    
    return head;
    
}

