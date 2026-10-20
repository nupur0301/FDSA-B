#include <iostream>
#include <list>
using namespace std;
class HashTable{
    list<int> table[10];
public:
    void insert(int key){
        int index = key % 10;
        table[index].push_back(key);
    }
    void display(){
        cout << "\nLibrary Shelves:" << endl;
        for (int i = 0; i < 10; i++){
            cout << i << " : ";
            for (int value : table[i])
                cout << value << " ";
            cout << endl;
        }
    }
};
int main(){
    HashTable h;
    int n, key;
    cout << "Enter number of books: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        cout << "Enter book code: ";
        cin >> key;
        h.insert(key);
    }
    h.display();
    return 0;
}