#include <iostream>
#include <string>
using namespace std;
class Node{
public:
    string page;
    Node *next;
    Node(string p){
        page = p;
        next = NULL;
    }
};

class BrowserHistory{
    Node *top;
public:
    BrowserHistory(){
        top = NULL;
    }
    void visit(string url){
        Node *newNode = new Node(url);
        newNode->next = top;
        top = newNode;

        cout << "Visited: " << url << endl;
        cout << "Current Page: " << top->page << endl;
    }
    void back(){
        if (top == NULL){
            cout << "No pages in history." << endl;
        }
        else if (top->next == NULL){
            cout << "Cannot go back. No previous page available." << endl;
            cout << "Current Page: " << top->page << endl;
        }
        else   {
            Node *temp = top;
            top = top->next;

            cout << "Back operation performed." << endl;
            cout << "Current Page: " << top->page << endl;

            delete temp;
        }
    }
    void currentPage()  {
        if (top == NULL)
            cout << "No page is currently open." << endl;
        else
            cout << "Current Page: " << top->page << endl;
    }
};
int main(){
    BrowserHistory browser;
    int choice;
    string url;
    do{
        cout << "\n---Browser History using Linked List---" << endl;
        cout << "1. Visit Page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Current Page" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
        case 1:
            cout << "Enter page URL: ";
            cin >> url;
            browser.visit(url);
            break;
        case 2:
            browser.back();
            break;
        case 3:
            browser.currentPage();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
    return 0;
}