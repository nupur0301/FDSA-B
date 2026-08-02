#include<iostream>
#include<string>
using namespace std;
int iterative(string plate[],int n,string k){
    for(int i=0;i<n;i++){
        if(plate[i]==k){
            return i;
        }
    } return -1;

}
int recursive(string plate[],int n, string k, int j){
    if(j==n){
        return -1;
    } 
    if(plate[j]==k){
        return j;
    }
    return recursive(plate,n, k,j+1);
}
int main(){
    int n;
    cout<<"Enter the number of car parked:";
    cin>>n;

    string car[n];

    cout<<"\nEnter the car plate number:";
    for(int i=0;i<n;i++){
        cin>>car[i];
    }

    string key;
    cout<<"Enter the plate number you want to find:";
    cin>>key;

    int result1=iterative(car,n,key);
    if(result1<0){
        cout<<"Car Not found";
    }
    else{
        cout<<"Car found at position: "<<result1+1<<endl;
    }
    int result2=recursive(car,n,key,0);
    if(result2<0){
        cout<<"car not found:"<<endl;
    }
    else{
        cout<<"Car found position:"<<result2+1<<endl;
    }
    return 0;
}

