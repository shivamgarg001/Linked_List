#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    

    node(int data){
        this->data=data;
        this->next=NULL;
        
    }
    ~node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
    

};
void insertathead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
   
}
void insertattail(node* &tail,int val){
    node* n= new node(val);
    tail->next=n;
    tail=n;

}
void insertatmiddle(node* &head,int pos,int val){
    if(pos==0){
        insertathead(head,val);
        return;
    }
    node* temp=head;
    node* n=new node(val);
    int j=0;
    while(j!=pos-1){
        temp=temp->next;
        j++;
    }
    n->next=temp->next;
    temp->next=n;
    
}

void deletion_by_position(node* &head,int position){
    node*temp1=head->next;
    node* temp=head;
    if(position==1){
        head=head->next;
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
    temp->next=temp1->next;
    temp1->next=NULL;
    delete temp1;

}
void deletion_by_value(node* &head,int value){
    node* temp1=head->next;
    node* temp=head;
    
    if(head->data==value){
        head=temp->next;
        return;
    }
    int position=1;
    while(true){
        if(temp->data==value){
            break;
        }
        temp=temp->next;
        position++;
    }
    temp=head;
    
    deletion_by_position(head,position);
    
}
void print(node* &head){
    node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    
}

int main(){

    node* node1=new node(1);
    node* head=node1;
    node* tail=node1;
    insertattail(tail,2);
    insertattail(tail,3);
    insertattail(tail,4);
    insertattail(tail,5);
    insertattail(tail,6);

    print(head);
    deletion_by_position(head,1);
    print(head);

    return 0;
}