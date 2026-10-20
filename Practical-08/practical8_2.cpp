#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)  {
        data = value;
        left = NULL;
        right = NULL;
    }
};
class BST{
public:
    Node *root;
    BST(){
        root = NULL;
    }
    Node* insert(Node *root, int value){
        if (root == NULL){
            return new Node(value);
        }
        if (value < root->data){
            root->left = insert(root->left, value);
        }
        else if (value > root->data)   {
            root->right = insert(root->right, value);
        }

        return root;
    }
    void inorder(Node *root){
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};
int main(){
    BST tree;
    int n, value;
    cout << "Enter number of book codes: ";
    cin >> n;
    for (int i = 1; i <= n; i++){
        cout << "Enter book code " << i << ": ";
        cin >> value;

        tree.root = tree.insert(tree.root, value);
    }
    cout << "\nInorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;
    return 0;
}