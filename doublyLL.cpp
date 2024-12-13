#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node* &head,int val){
    node* newNode=new node(val);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}


void insertAtTail(node* &head,int val){

    node* newNode=new node(val);

    if (head == NULL) {  // If the list is empty, make the new node the head
        head = newNode;
        return;
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}

void display(node* head){

    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

void deletion(node* &head,int val){

    node* temp=head;

    while(temp!=NULL && temp->data!=val){
        temp=temp->next;
    }
    // temp->next=temp->next->next;
    // temp->prev=temp->prev->prev;

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
    
    
}

node* mergeSortedLinkedlist(node* &head1,node* &head2){

    node* m1=head1;
    node* m2=head2;
    node* m3=new node(-1);


    while(m1!=NULL && m2!=NULL){
        if(m1->data<m2->data){
            m3->next=m1;
            m1=m1->next;
            
        }else{
            m3->next=m2;
            m2=m2->next;
            
        }
        m3=m3->next;
    }   

    while(m1!=NULL){
        m3->next=m1;
        m1=m1->next;
        m3=m3->next;
    }

     while(m2!=NULL){
        m3->next=m2;
        m2=m2->next;
        m3=m3->next;
    }

    return m3->next;

}


int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head,10);
    display(head);
    deletion(head,10);
    display(head);
    mergeSortedLinkedlist(head,9,head,4);
    mergeSortedLinkedlist(head,3,head,66);
    mergeSortedLinkedlist(head,36,head,8);
    display(head);

    return 0;
}