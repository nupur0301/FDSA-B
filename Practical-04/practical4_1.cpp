#include<iostream>
using namespace std;

class Node{
  public:
    Node *next;
    int token;
};
Node *head = NULL;
void insert_at_front(){
    Node *newNode = new Node;
    cout<<"Enter token number: ";
    cin>>newNode->token;

    if(head==NULL){
        newNode->next = NULL;
        head = newNode;
        cout<<"Patient with token no. "<<newNode->token<<" added successfully";
    } else{
        newNode->next = head;
        head = newNode;
        cout<<"Patient with token no. "<<newNode->token<<" added successfully";
    }
}
void insert_at_end(){
    Node *newNode = new Node;
    cout<<"Enter token number: ";
    cin>>newNode->token;
    newNode->next = NULL;

    if(head== NULL){
        head=newNode;
        cout<<"Added!!";
    }
    else{
        Node *temp = head;

        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next= newNode;
        cout<<"Added successfully!!";
    }
}
void insert_at_specific_position(){
    Node *newNode = new Node;
    cout<<"Enter token number:";
    cin>>newNode->token;
    int pos;
    cout<<"Enter position where you wnat to enter:";
    cin>>pos;
    Node *temp = head;
    if(pos<=0){
        cout<<"ENTER VALID POS...";
        return;
    }
    if(pos==1){
        newNode->next = head;
        head = newNode;
        cout<<"ADDED SUCCESSFULLY!!"<<endl;
        return; 
    }
    else{
        
        for(int i=1;i<pos-1 &&temp!=    NULL;i++){
            temp = temp->next;
        }
        if(temp==NULL){
            cout<<"Invalid position"<<endl;
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void display(){
    if(head==NULL){
        cout<<"No queue"<<endl;
        return;
    }

    Node *temp = head;
    while(temp!= NULL){
        cout<<temp->token<<" ";
        temp= temp->next;
    }
    cout<<endl;

}
int main(){
    int choice;
    do{
        cout<<"\n===== Hospital Queue =====";
        cout<<"\n1. Insert Critical Patient (Beginning)";
        cout<<"\n2. Insert Routine Patient (End)";
        cout<<"\n3. Insert Priority Patient (Position)";
        cout<<"\n4. Display Queue";
        cout<<"\n5. Exit";

        cout<<"Enter your choice:";
        cin>>choice;
        
        switch(choice){
            case 1: insert_at_front();
            cout<<endl;
            cout<<"QUEUE:";
            display();
            break;

            case 2: insert_at_end();
            cout<<"QUEUE:";
            display();
            break;

            case 3: insert_at_specific_position();
            cout<<"QUEUE:";
            display();
            break;

            case 4:display();
            break;

            case 5: cout<<"Thank you..."<<endl;
            break;

            default:
            cout<<"Enter valid choice";
        }
    }while(choice!=5);
    return 0;
}
