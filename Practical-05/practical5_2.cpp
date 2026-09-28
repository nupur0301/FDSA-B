#include <iostream>
using namespace std;
struct SNode{
    int data;
    SNode *next;

    SNode(int x)  {
        data = x;
        next = NULL;
    }
};
class SinglyCircular{
    SNode *head;
public:
    SinglyCircular(){
        head = NULL;
    }
    void insert(int x){
        SNode *newNode = new SNode(x);
        if (head == NULL){
            head = newNode;
            newNode->next = head;
            return;
        }
        SNode *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    void remove(int x){
        if (head == NULL){
            cout << "Circle is Empty.\n";
            return;
        }
        SNode *temp = head;
        SNode *prev = NULL;
        do{
            if (temp->data == x)
                break;
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        if (temp->data != x){
            cout << "Student not found.\n";
            return;
        }
        if (temp == head){
            if (head->next == head){
                delete head;
                head = NULL;
                return;
            }
            SNode *last = head;
            while (last->next != head)
                last = last->next;
            head = head->next;
            last->next = head;
            delete temp;
        }
        else   {
            prev->next = temp->next;
            delete temp;
        }
    }
    void display(){
        if (head == NULL){
            cout << "Circle is Empty.\n";
            return;
        }
        SNode *temp = head;
        do{
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(Head)\n";
    }
};
struct DNode{
    int data;
    DNode *prev;
    DNode *next;
    DNode(int x)  {
        data = x;
        prev = NULL;
        next = NULL;
    }
};
class DoublyCircular{
    DNode *head;
public:
    DoublyCircular(){
        head = NULL;
    }
    void insert(int x){
        DNode *newNode = new DNode(x);
        if (head == NULL){
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
        DNode *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
    void remove(int x){
        if (head == NULL){
            cout << "Circle is Empty.\n";
            return;
        }
        DNode *temp = head;
        do{
            if (temp->data == x)
                break;
            temp = temp->next;

        } while (temp != head);
        if (temp->data != x){
            cout << "Student not found.\n";
            return;
        }
        if (temp->next == temp){
            delete temp;
            head = NULL;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == head)
            head = temp->next;
        delete temp;
    }
    void display(){
        if (head == NULL){
            cout << "Circle is Empty.\n";
            return;
        }
        DNode *temp = head;
        do{
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(Head)\n";
    }
};
int main(){
    SinglyCircular s;
    DoublyCircular d;
    int choice, value;
    do{
        cout << "\n========== STUDENT CIRCLE MENU ==========\n";
        cout << "1. Student Joins Circle\n";
        cout << "2. Student Leaves Circle\n";
        cout << "3. Display Circle\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
        case 1:
            cout << "Enter Student ID: ";
            cin >> value;
            s.insert(value);
            d.insert(value);
            cout << "\nStudent added successfully.\n";
            cout << "Singly Circular: ";
            s.display();
            cout << "DoUbly Circular: ";
            d.display();
            break;
        case 2:
            cout << "Enter Student ID to remove: ";
            cin >> value;
            s.remove(value);
            d.remove(value);
            cout << "\nSingly Circular: ";
            s.display();
            cout << "Doubly Circular: ";
            d.display();
            break;
        case 3:
            cout << "\nSingly Circular: ";
            s.display();
            cout << "Doubly Circular: ";
            d.display();
            break;
        case 4:
            cout << "\nThank You!\n";
            break;
        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);
    return 0;
}