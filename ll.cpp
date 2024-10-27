#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};


void insertAtTail(node* &head,int val){

    node* newNode = new node(val);

    if(head==NULL){
        head=newNode;
        return;
    }
    node* temp;

    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newNode;
}

void insetAtHead(node* &head,int val){

    node* n=new node(val);
    n->next=head;
    head=n;
     
}

void display(node* head){

    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"null"<<endl;
}


bool search(node* head,int key){

    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}


void deletion(node* head,int key){

    node* temp=head;

    while(temp->next->data!=key){

            temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;

}

void deleteAtHead(node* &head){

    node* todelete=head;
    head=head->next;
    delete todelete;
}


void reverse(node* &head){

    node* prev=NULL;
    node* curr=head;
    node* next;

    while(curr!=NULL){
        
        next=curr->next;
        
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    head=prev;

}


// void revereseRecursive(node* &head){

//     node* n= revereseRecursive(head->next);
//     head->next->next=head;
//     head->next=NULL;
//      head=n;
// }

void reverseRecursive(node*& head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    node* rest = head->next;
    reverseRecursive(rest);

    head->next->next = head;
    head->next = NULL;
    head = rest;
}


node* revereseKnodes(node* &head,int val){
    node* prev=NULL;
    node* curr=head;
    node* next;

        int c=0;
    while(curr!=NULL && c<val){
        next=curr->next;

        curr->next=prev;
        prev=curr;
        curr=next;
        c++;
    }

    if(next!=NULL){
            head->next=revereseKnodes(next,val);
    }
    return prev;
}

int main(){

    node* head=NULL;
    insertAtTail(head,5);
    insertAtTail(head,55);
    insertAtTail(head,555);
    insertAtTail(head,5555);

    display(head);

    // insetAtHead(head,4);
    // display(head);
    // cout<<search(head,55)<<endl;
    // deletion(head,5);
    // deleteAtHead(head);
    // deleteAtHead(head);
    // reverse(head);
    // reverseRecursive(head);
    head = revereseKnodes(head,2);
    display(head);
    return 0;
}