#include <iostream>
#include <string>
using namespace std;
class Node{
public:
    string patient;
    Node *next;
    Node(string name)  {
        patient = name;
        next = NULL;
    }
};
class Queue{
    Node *front, *rear;
public:
    Queue(){
        front = rear = NULL;
    }
    void arrive(string name){
        Node *newNode = new Node(name);
        if (front == NULL){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
        cout << name << " arrived at the hospital." << endl;
        cout << "Front patient: " << front->patient << endl;
    }
    void attend(){
        if (front == NULL){
            cout << "No patients waiting." << endl;
            return;
        }
        Node *temp = front;
        cout << front->patient << " attended by the doctor." << endl;
        front = front->next;
        if (front == NULL){
            rear = NULL;
        } else{
            cout << "Front patient: " << front->patient << endl;
        }
        delete temp;
    }
    void frontPatient(){
        if (front == NULL){
            cout << "No patients waiting." << endl;
        } else{
            cout << "Front patient: " << front->patient << endl;
        }
    }
    void display(){
        if (front == NULL){
            cout << "No patients waiting." << endl;
            return;
        }
        Node *temp = front;
        cout << "Patients in queue: ";
        while (temp != NULL){
            cout << temp->patient << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    Queue q;
    int choice;
    string name;
    do{
        cout << "\n---Hospital Queue using Linked List---" << endl;
        cout << "1. Arrive" << endl;
        cout << "2. Attend" << endl;
        cout << "3. Front Patient" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
        case 1:
            cout << "Enter patient name: ";
            cin >> name;
            q.arrive(name);
            break;
        case 2:
            q.attend();
            break;
        case 3:
            q.frontPatient();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
   return 0;
}