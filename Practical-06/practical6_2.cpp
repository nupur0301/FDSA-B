#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    string page;
    Node *next;
};
Node *top = NULL;
void visitPage()
{
    Node *newNode = new Node;

    cout << "Enter Page URL: ";
    cin >> newNode->page;

    newNode->next = top;
    top = newNode;

    cout << "Page Visited Successfully." << endl;
    cout << "Current Page: " << top->page << endl;
}
void backPage()
{
    if(top == NULL){
        cout << "No page in browser history." << endl;
        return;
    }
    Node *temp = top;
    cout << "Leaving Page: " << top->page << endl;
    top = top->next;
    delete temp;
    if(top == NULL){
        cout << "No Current Page (History Empty)." << endl;
        return;
    }
        cout << "Current Page: " << top->page << endl;
}
void currentPage(){
    if(top == NULL){
        cout << "No Current Page." << endl;
        return;
    }
        cout << "Current Page: " << top->page << endl;
}

int main(){
    int choice;
    do
    {
        cout << "\n===== Browser History =====" << endl;
        cout << "1. Visit Page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Current Page" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                visitPage();
                break;
            case 2:
                backPage();
                break;
            case 3:
                currentPage();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid Choice!" << endl;
        }
    }while(choice != 4);
    return 0;
}