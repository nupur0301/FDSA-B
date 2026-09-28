#include <iostream>
#include <string>
using namespace std;
class Node{
public:
    string song;
    Node *prev;
    Node *next;
    Node(string s)  {
        song = s;
        prev = NULL;
        next = NULL;
    }
};
class Playlist{
private:
    Node *head;
    Node *tail;
public:
    Playlist(){
        head = NULL;
        tail = NULL;
    }
    void addAtBeginning(string song){
        Node *newNode = new Node(song);

        if (head == NULL){
            head = tail = newNode;
        }
        else   {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        cout << "\nSong added at beginning.\n";
        display();
    }
    void addAtEnd(string song){
        Node *newNode = new Node(song);
        if (head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "\nSong added at end.\n";
        display();
    }
    void insertAfterSong(string target, string newSong){
        Node *temp = head;
        while (temp != NULL && temp->song != target){
            temp = temp->next;
        }
        if (temp == NULL){
            cout << "\nSong not found.\n";
            return;
        }
        Node *newNode = new Node(newSong);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL){
            temp->next->prev = newNode;
        }
        else{
            tail = newNode;
        }
        temp->next = newNode;
        cout << "\nSong inserted successfully.\n";
        display();
    }
    void deleteFirst(){
        if (head == NULL){
            cout << "\nPlaylist is empty.\n";
            return;
        }
        Node *temp = head;
        if (head == tail){
            head = tail = NULL;
        }
        else{
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
        cout << "\nFirst song deleted.\n";
        display();
    }
    void countSongs()
    {
        int count = 0;
        Node *temp = head;
        while (temp != NULL){
            count++;
            temp = temp->next;
        }
        cout << "\nTotal Songs = " << count << endl;
    }
    void display()
    {
        if (head == NULL){
            cout << "Playlist is Empty.\n";
            return;
        }
        Node *temp = head;
        cout << "Playlist : ";
        while (temp != NULL){
            cout << temp->song;
            if (temp->next != NULL){
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Playlist p;
    int choice;
    string song, target;
    do
    {
        cout << "\n========== MUSIC PLAYLIST ==========\n";
        cout << "1. Add Song at Beginning\n";
        cout << "2. Add Song at End\n";
        cout << "3. Insert Song After Given Song\n";
        cout << "4. Delete First Song\n";
        cout << "5. Count Songs\n";
        cout << "6. Display Playlist\n";
        cout << "7. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Song Name : ";
            cin >> song;
            p.addAtBeginning(song);
            break;
        case 2:
            cout << "Enter Song Name : ";
            cin >> song;
            p.addAtEnd(song);
            break;
        case 3:
            cout << "Enter Existing Song : ";
            cin >> target;

            cout << "Enter New Song : ";
            cin >> song;

            p.insertAfterSong(target, song);
            break;
        case 4:
            p.deleteFirst();
            break;
        case 5:
            p.countSongs();
            break;
        case 6:
            p.display();
            break;
        case 7:
            cout << "\nThank You!\n";
            break;
        default:
            cout << "\nInvalid Choice.\n";
        }
    } while (choice != 7);
    return 0;
}