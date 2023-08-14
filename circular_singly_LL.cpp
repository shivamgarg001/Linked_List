#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    

    node(int data){
        this->data=data;
        this->next=next;
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
    node*temp=tail;
    if(tail==NULL){
        tail=n;
        tail->next=n;
    }
    else{
        while(temp->data!=element){
            temp=temp->next;
        }
        n->next=temp->next;
        temp->next=n;
    }
    

}
void deletion_by_value(node* &tail,int value){
    node* temp=tail;
    node* temp1=tail->next;
    if(tail==NULL){
        cout<<"list is empty nothing to delete";
        return;
    }
    if(temp=temp1){
        tail=NULL;
        return;
    }
    while(temp1->data!=value){
        temp=temp->next;
        temp1=temp1->next;
    }
    temp->next=temp1->next;
    if(tail==temp1){
        tail=temp;
    }
    temp1->next=NULL;
    delete temp1;
}
void print(node* tail){
    node* temp=tail;
    if(tail==NULL){
        cout<<"nothing to print";
        return;
    }
    else{
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=tail);
    cout<<endl;
    }
}
int main(){
    node* tail=NULL;
    insertnode(tail,9,5);
    print(tail);
    insertnode(tail,5,4);
    print(tail);
    insertnode(tail,4,3);
    print(tail);
    insertnode(tail,3,2);
    print(tail);
    deletion_by_value(tail,3);
    print(tail);
    
    
    return 0;
}