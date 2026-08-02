#include <iostream>
using namespace std;

int main() {
    int n, h;

    cout<<"Enter number of items: ";
    cin>>n;

    string arr[n];

    cout<<"Enter items:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout<<"Enter number of hours: ";
    cin>>h;

    int k=h%n;

    cout<<"Final display order: ";
    for(int i=k;i<n; i++) {
        cout<<arr[i]<<" ";
    }

    for (int i=0;i<k;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}