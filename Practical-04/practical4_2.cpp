#include<iostream>
using namespace std;

class Node{
public:
    int token;
    Node *next;
};
Node *front = NULL;
Node *rear = NULL;
void enqueue(){
    Node *newNode = new Node;
    cout << "Enter Patient Token: ";
    cin >> newNode->token;
    newNode->next = NULL;
    if(front == NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
   cout << "Patient Added Successfully!" << endl;
}
void deleteByValue(){
    if(front == NULL){
        cout << "Queue is Empty!" << endl;
        return;
    }
    int value;
    cout << "Enter Patient Token to Delete: ";
    cin >> value;
    if(front->token == value){
        Node *temp = front;
        front = front->next;

        if(front == NULL)
        {
            rear = NULL;
        }

        delete temp;
        cout << "Patient Removed Successfully!" << endl;
        return;
    }
    Node *temp = front;
    Node *prev = NULL;
    while(temp != NULL && temp->token != value){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        cout << "Patient Token Not Found!" << endl;
        return;
    }
    prev->next = temp->next;
    if(temp == rear){
        rear = prev;
    }
    delete temp;
    cout << "Patient Removed Successfully!" << endl;
}
void display(){
    if(front == NULL){
        cout << "Queue is Empty!" << endl;
        return;
    }
    Node *temp = front;
    cout << "\nPatients in Queue:\n";
    while(temp != NULL){
        cout << temp->token << " ";
        temp = temp->next;
    }
    cout << endl;
}
void reversePrint(Node *temp)
{
    if(temp == NULL)
    {
        return;
    }
    reversePrint(temp->next);
    cout << temp->token << " ";
}
int main()
{
    int choice;
    do
    {
        cout << "\n===== Hospital Queue Menu =====" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Delete Patient by Token" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Reverse Print Queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch(choice){
        case 1:enqueue();
               break;
        case 2:deleteByValue();
               break;
        case 3:display();
               break;
        case 4:if(front == NULL){
                cout << "Queue is Empty!" << endl;
            }
            else{
                cout << "Queue in Reverse:\n";
                reversePrint(front);
                cout << endl;
            }
            break;
        case 5:
            cout << "Exiting Program..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while(choice != 5);
    return 0;
}