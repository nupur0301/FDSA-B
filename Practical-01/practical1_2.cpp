#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of books borrowed: ";
    cin>>n;

    int books[n];

    cout<<"Enter book IDs: ";
    for(int i=0; i<n; i++) {
        cin>>books[i];
    }
    bool found=false;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (books[i]==books[j]) {
                found=true;
                break;
            }
        }
        if (found)
            continue;

        for (int j= i + 1; j<n; j++) {
            if (books[i]==books[j]) {
                cout<<books[i] <<" ";
                break;
            }
        }
    }

    return 0;
}