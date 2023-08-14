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
        this->next=next;
        this->prev=prev;
    }

    ~node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void insertnode(node* &tail,int element,int value){
    node* n=new node(value);
    if(tail==NULL){
        tail=n;
        tail->next=n;
        tail->prev=n;
        
    }
    else{
        node* temp=tail;
        while(temp->data!=element){
            temp=temp->next;
        }
        n->next=temp->next;
        n->prev=temp;
        temp->next->prev=n;
        temp->next=n;
    }
}
void deletion_by_value(node* &tail,int value){
    node* temp=tail;
    node* temp1=tail->next;
    if(tail==NULL){
        cout<<"nothing to delete";
        return;
    }
    else if(temp==temp1){
        tail=NULL;
        return;
    }
    else{
        while(temp1->data!=value){
            temp=temp->next;
            temp1=temp1->next;
        }
        temp->next=temp1->next;
        temp1->next->prev=temp;
        if(tail==temp1){
            tail=temp;
        }
        
        temp1->next=NULL;
        temp1->prev=NULL;
        delete temp1;
        
    }
}
void print(node* tail){
    if(tail==NULL){
        cout<<"nothing to print";
        return;
    }
    node* temp = tail->next; 
    do {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp != tail->next); 
    cout << endl;
}
int main(){

    node* tail=NULL;
    insertnode(tail,5,56);
    print(tail);
    insertnode(tail,56,57);
    print(tail);
    insertnode(tail,57,58);
    print(tail);
    insertnode(tail,56,45);
    print(tail);
    insertnode(tail,45,46);
    print(tail);
    deletion_by_value(tail,56);
    print(tail);

    return 0;
}
