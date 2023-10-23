#include<iostream>
using namespace std;

    class Node{
        public:
        int data;
        Node* next;
        Node*prev;

        Node(int d){
            data=d;
            prev=NULL;
            next=NULL;
        }
        ~Node(){
            int val=this->data;
            if(next!=NULL){
                delete next;
                next=NULL;
            }
            cout<<"Memory free for node with data "<<val<<endl;
        }
    };
    void InsertAtHead(Node* &head,int d){
     Node*temp=new Node(d);
     temp->next=head;
     head->prev=temp;
     head=temp;

    }
    void InsertAtTail(Node* &tail,int d){
        Node*temp=new Node(d);
        
         temp->prev=tail;
          tail->next=temp;
         tail=temp;
    }
    void InsertAtPosition(Node* &head,Node* &tail,int d,int position){
       if(position==1){
        InsertAtHead(head,d);

        return;
       }
        
       Node*temp=head;
       int cnt=1;
       while(cnt<position-1){
        temp=temp->next;
        cnt++;

}   if(temp->next==NULL){
        
        InsertAtTail(tail,d);
        
        return;
       }
       Node* nodetoinsert=new Node(d);
       nodetoinsert->next=temp->next;
       temp->next->prev=nodetoinsert;
       temp->next=nodetoinsert;
       nodetoinsert->prev=temp;      
      
     }
     void DeleteNode(Node*&head,int position){
        if(position==1){
            Node*temp=head;
            temp->next->prev=NULL;
            head=temp->next;
            temp->next=NULL;
            delete temp;
        }
        else{
            Node*curr=head;
            Node*prev=NULL;
            int cnt=1;
            while(cnt<position){
                prev=curr;
                curr=curr->next;
                cnt++;
            }
            curr->prev=NULL;
            prev->next=curr->next;
            curr->next=NULL;
            delete curr;
        }
     }
    void print(Node* &head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int getlength(Node* &head){
        int len=0;
        Node*temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
            
        }
        return len;
    }
    int main(){
    Node *node1=new Node(10);
    Node*head=node1;
    Node*tail=node1;
    InsertAtHead(head,20);
    InsertAtHead(head,30);
   
    InsertAtTail(tail,40);
    InsertAtTail(tail,50);
    InsertAtPosition(head,tail,100,3);
      print(head); 
      DeleteNode(head,4); 
      print(head);
       return 0;
    }

