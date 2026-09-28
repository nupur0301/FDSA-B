#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter Maximum Capacity of Tray Stack: ";
    cin >> n;
    int stack[100];
    int top = -1;
    int choice, tray;
    do{
        cout << "\n===== Tray Stack Menu =====\n";
        cout << "1. Place Tray\n";
        cout << "2. Take Tray\n";
        cout << "3. Display Top Tray\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)  {
            case 1:
                if(top == n - 1){
                    cout << "Error: Tray Stack is Full! Cannot place more trays." << endl;
                    return;
                }
                    cout << "Enter Tray Number: ";
                    cin >> tray;

                    top++;
                    stack[top] = tray;

                    cout << "Tray Placed Successfully." << endl;
                    cout << "Current Top Tray: " << stack[top] << endl;
                break;
            case 2:
                if(top == -1){
                    cout << "Error: Tray Stack is Empty! No tray to take." << endl;
                    break;
                }
                    cout << "Tray Taken: " << stack[top] << endl;
                    top--;

                    if(top == -1){
                        cout << "Tray Stack is now Empty." << endl;
                        return;
            }
                        cout << "Current Top Tray: " << stack[top] << endl;
                break;
            case 3:
                if(top == -1){
                    cout << "Tray Stack is Empty." << endl;
                    return;
                }
                    cout << "Current Top Tray: " << stack[top] << endl;
                break;
            case 4:
                cout << "Exiting Program..." << endl;
                break;
            default:   
                cout << "Invalid Choice!" << endl;
            
        }
    } while(choice != 4);
    return 0;
}