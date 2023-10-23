#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int d){
        data=d;
        next=NULL;
    }
};
void print(Node*& head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}
void InsertAtHead(Node* &head,int d){
    Node*temp=new Node(d);
    temp->next=head;
    head=temp;
}
Node* Reversedll(Node* &head){
    Node*prev=NULL;
    Node*curr=head;
    if(head==NULL || head->next==NULL){
        return head;
    }
    while(curr!=NULL){
        Node * forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;

    }
    return prev;
}
int main(){
    Node*head=NULL;
    InsertAtHead(head,100);
    InsertAtHead(head,90);
    InsertAtHead(head,80);
    print(head);
    Reversedll(head);
    print(head);
    return 0;
}
cd google-clone
npm start
open src folder app.js file  content from class name upto <div>
remove h1 Lets build google clone  
go to vs code go to project name-google-clone click on src app.js from header to close remove 
add <h1> Lets build google clone </h1>