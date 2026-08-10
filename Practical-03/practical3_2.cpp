#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int arr[n];

    cout<<"Enter the elements(0,1,2): ";
    for(int i=0; i< n;i++) {
        cin >> arr[i];
    }

    cout << "\nArray: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "\nSorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
