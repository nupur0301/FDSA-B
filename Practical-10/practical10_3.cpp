#include <iostream>
using namespace std;
class HashTable{
    int table[10];
public:
    HashTable(){
        for (int i = 0; i < 10; i++)
            table[i] = -1;
    }
    void insert(int key){
        int h1 = key % 10;
        int h2 = 7 - (key % 7);
        int i = 0;
        while (i < 10) {
            int index = (h1 + i * h2) % 10;
            if (table[index] == -1){
                table[index] = key;
                return;
            }
            i++;
        }
        cout << "Hash table is full. Cannot insert " << key << endl;
    }
    void display(){
        cout << "\nHash Table:" << endl;
        for (int i = 0; i < 10; i++)
            cout << i << " : " << table[i] << endl;
    }
};
int main(){
    HashTable h;
    int n, key;
    cout << "Enter number of student IDs: ";
    cin >> n;
    for (int i = 0; i < n; i++)    {
        cout << "Enter student ID: ";
        cin >> key;
        h.insert(key);
    }
    h.display();
   return 0;
}