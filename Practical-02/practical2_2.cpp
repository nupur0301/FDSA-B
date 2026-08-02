#include <iostream>
using namespace std;
int iterative(int arr[], int n, int key) {
    int low=0, high=n-1;

    while(low<=high) {
        int mid=(low+high)/2;

        if (arr[mid]==key)
            return mid;

        else if(arr[mid]<key)
            low=mid+1;

        else
            high=mid-1;
    }
    return -1;
}
int recursive(int arr[], int low, int high, int key) {

    if(low>high)
        return -1;
    int mid=(low+high)/2;
    if (arr[mid]==key)
        return mid;
    else if (arr[mid]<key)
        return recursive(arr,mid+1,high,key);
    else
        return recursive(arr,low,mid-1,key);
}
int main() {
    int n;
    cout<<"Enter number of books:";
    cin>>n;
    int arr[n];
    cout<<"Enter sorted book codes:\n";
    for (int i=0;i<n;i++)
        cin>>arr[i];
    int key;
    cout<<"key";
    cin>>key;
    int result1=iterative(arr,n, key);
    int result2 = recursive(arr,0,n-1,key);
    if (result1<0){
        cout<<"Book not found\n";
    }
    else{
        cout<<"Book found at position"<<result1+1<<endl;
    }
    if(result2 <0)
        cout << "Book not found";
    else
        cout << "Book found at position "<<result2+1;
    return 0;
}