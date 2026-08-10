#include <iostream>
using namespace std;

int main() {
    int n;

    //Bubble Sort 
    cout << "Enter the number of papers: ";
    cin >> n;

    int arr1[n];

    cout << "Enter the marks:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cout << "Entered Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }

    for (int i = 0;i<n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr1[j] > arr1[j + 1]) {
                swap(arr1[j], arr1[j + 1]);
            }
        }
    }
    cout << "\nSorted using Bubble Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }

    cout << "\n\nEnter the size of second array: ";
    cin >> n;
    int arr2[n];
    cout << "Enter the marks:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    cout << "Entered Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr2[j] < arr2[min]) {
                min = j;
            }
        }
        swap(arr2[i], arr2[min]);
    }
    cout << "\nSorted using Selection Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    // Insertion Sort
    cout<< "\n\nEnter the size of third array: ";
    cin>> n;
    int arr3[n];
    cout<<"Enter the marks:\n";
    for (int i=0;i<n; i++) {
        cin>>arr3[i];
    }
        cout<<"Entered Array: ";
    for (int i=0; i<n; i++) {
        cout << arr3[i] << " ";
    }
    for (int i=1; i<n; i++) {
        int key=arr3[i];
        int j=i-1;

        while (j>= 0&&arr3[j]>key) {
            arr3[j+1]=arr3[j];
            j--;
        }
        arr3[j+1]=key;
    }
    cout << "\nSorted using Insertion Sort: ";
    for (int i=0; i<n; i++) {
        cout<<arr3[i]<< " ";
    }
    return 0;
}