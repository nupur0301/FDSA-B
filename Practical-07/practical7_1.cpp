#include <iostream>
using namespace std;
class Queue{
    int arr[100];
    int front, rear, size;
public:
    Queue(int n){
        size = n;
        front = -1;
        rear = -1;
    }
    void enqueue(int value){
        if (rear == size - 1){
            cout << "Queue Overflow! Cannot insert " << value << "." << endl;
            return;
        }

        if (front == -1){
            front = 0;
        }
        rear++;
        arr[rear] = value;
        cout << value << " joined the queue." << endl;
        cout << "Front token: " << arr[front] << endl;
        
    }
    void dequeue(){
        if (front == -1 || front > rear){
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }
        cout << arr[front] << " served from the queue." << endl;
        front++;
        if (front > rear){
            front = rear = -1;
            cout << "Queue is now empty." << endl;
        }
        else   {
            cout << "Front token: " << arr[front] << endl;
        }
    }
    void display(){
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void frontElement()  {
        if (front == -1)
            cout << "Queue is empty." << endl;
        else
            cout << "Front token: " << arr[front] << endl;
    }
};
int main(){
    int n;
    cout << "Enter queue size: ";
    cin >> n;
    Queue q(n);
    int choice, value;
    do{
        cout << "\n---Queue using Array---" << endl;
        cout << "1. Join (Enqueue)" << endl;
        cout << "2. Serve (Dequeue)" << endl;
        cout << "3. Front Token" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
        case 1:
            cout << "Enter token number: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.frontElement();
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