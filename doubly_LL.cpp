#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }

    ~node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

int getlength(node* &head){
    int len=0;
    node*temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}

void insertathead(node* &tail,node* &head,int value){
    if(head==NULL){
        node* n=new node(value);
        head=n;
        tail=n;
    }
    else{
        node* n=new node(value);
        n->next=head;
        head->prev=n;
        head=n;
    }

}

void insertattail(node* &head,node* &tail,int value){
    if(tail==NULL){
        node* n=new node(value);
        tail=n;
        head=n;
    }
    else{
        node* n=new node(value);
        node* temp=tail;
        temp->next=n;
        n->prev=temp;
        tail=n;
    }

}

void insertatmiddle(node* &tail,node* &head,int value,int position){
    node* n=new node(value);
    node* temp=head;
    
    if(position==1){
        insertathead(tail,head,value);
        return;
    }
    
    
    int j=2;
    while(j<position){
        temp=temp->next;
        j++;
    }
    if(temp->next==NULL){
        insertattail(head,tail,value);
        return;
    }

    n->prev=temp;
    temp->next->prev=n;
    n->next=temp->next;
    temp->next=n;
    

}

void deletion_by_position(node* &head,int position){
    node* temp=head;
    node* temp1=head->next;
    if(position==1){
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    
    int j=2;
    while(j!=position){
        temp=temp->next;
        temp1=temp1->next;
        j++;
    }
    
    temp1->prev=NULL;
    temp->next=temp1->next;
    temp1->next=NULL;
    delete temp1;
    
}

void print(node* &head){
    node* temp=head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}



int main(){
    
    node* head=NULL;
    node* tail=NULL;
    insertathead(tail,head,12);
    insertattail(head,tail,100);
    insertatmiddle(tail,head,11,3);
    print(head);
    deletion_by_position(head,1);
    print(head);
    
    return 0;
}