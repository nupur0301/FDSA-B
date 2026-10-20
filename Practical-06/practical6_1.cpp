#include <iostream>
using namespace std;
class Stack{
    int arr[100];
    int top;
    int size;
public:
    Stack(int n){
        size = n;
        top = -1;
    }
    void push(int value){
        if (top == size - 1){
            cout << "Stack Overflow! Cannot push " << value << "." << endl;
        }
        else   {
            top++;
            arr[top] = value;
            cout << value << " pushed into the stack." << endl;
        }
    }
    void pop() {
        if (top == -1){
            cout << "Stack Underflow! Stack is empty." << endl;
        }
        else   {
            cout << arr[top] << " popped from the stack." << endl;
            top--;
        }
    }
    void peek(){
        if (top == -1){
            cout << "Stack is empty." << endl;
        }
        else   {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
    void display() {
        if (top == -1){
            cout << "Stack is empty." << endl;
        } else{
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main(){
    int n;
    cout << "Enter the size of stack: ";
    cin >> n;
    Stack s(n);
    int choice, value;
    do{
        cout << "\n---Stack using array---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
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