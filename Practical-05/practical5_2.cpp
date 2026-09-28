#include <iostream>
using namespace std;
struct SNode {
    int data;
    SNode *next;
    SNode(int x) {
        data = x;
        next = NULL;
    }
};
class SinglyCircular {
    SNode *head;
public:
    SinglyCircular() {
        head = NULL;
    }
    void insert(int x) {
        SNode *newNode = new SNode(x);
        if (head == NULL) {
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
    void remove(int x) {
        if (head == NULL)
            return;
        SNode *temp = head;
        SNode *prev = NULL;
        do {
            if (temp->data == x)
                break;
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        if (temp->data != x)
            return;
        if (temp == head) {
            if (head->next == head) {
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
        else {
            prev->next = temp->next;
            delete temp;
        }
    }
    void display() {
        if (head == NULL) {
            cout << "Empty" << endl;
            return;
        }
        SNode *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
struct DNode {
    int data;
    DNode *prev;
    DNode *next;
    DNode(int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};
class DoublyCircular {
    DNode *head;
public:
    DoublyCircular() {
        head = NULL;
    }
    void insert(int x) {
        DNode *newNode = new DNode(x);
        if (head == NULL) {
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
    void remove(int x) {
        if (head == NULL)
            return;
        DNode *temp = head;
        do {
            if (temp->data == x)
                break;
            temp = temp->next;
        } while (temp != head);
        if (temp->data != x)
            return;
        if (temp->next == temp) {
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
    void display() {
        if (head == NULL) {
            cout << "Empty" << endl;
            return;
        }
        DNode *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};
int main() {
    SinglyCircular s;
    DoublyCircular d;
    int n;
    cout << "Enter number of operations: ";
    cin >> n;
    while (n--) {
        int choice, value;

        cout << "1. Join  2. Leave  3. Display" << endl;
        cin >> choice;
        if (choice == 1) {
            cin >> value;

            s.insert(value);
            d.insert(value);

            cout << "Singly Circular: ";
            s.display();

            cout << "Doubly Circular: ";
            d.display();
        }
        else if (choice == 2) {
            cin >> value;

            s.remove(value);
            d.remove(value);

            cout << "Singly Circular: ";
            s.display();

            cout << "Doubly Circular: ";
            d.display();
        }
        else if (choice == 3) {
            cout << "Singly Circular: ";
            s.display();

            cout << "Doubly Circular: ";
            d.display();
        }
    }
    return 0;
}