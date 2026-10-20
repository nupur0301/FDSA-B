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
        int index = key % 10;
        int start = index;
        while (table[index] != -1){
            index = (index + 1) % 10;
            if (index == start){
                   cout << "Parking lot is full. Cannot insert " << key << endl;
                return;
            }
        }
        table[index] = key;
    }
    void display()  {
        cout << "\nParking Slots:" << endl;

        for (int i = 0; i < 10; i++)
            cout << i << " : " << table[i] << endl;
    }
};
int main(){
    HashTable h;
    int n, key;
    cout << "Enter number of vehicles: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        cout << "Enter vehicle number: ";
        cin >> key;
        h.insert(key);
    }
    h.display();
   return 0;
}