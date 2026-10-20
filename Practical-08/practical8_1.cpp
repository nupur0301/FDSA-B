#include <iostream>
#include <queue>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};
class BinaryTree{
public:
    Node *root;
    BinaryTree(){
        root = NULL;
    }
    Node* createTree(){
        int value;
        cout << "Enter node value (-1 for NULL): ";
        cin >> value;
        if (value == -1)
            return NULL;
        Node *newNode = new Node(value);
        cout << "Enter left child of " << value << endl;
        newNode->left = createTree();
        cout << "Enter right child of " << value << endl;
        newNode->right = createTree();
        return newNode;
    }

    void inorder(Node *root){
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void preorder(Node *root){
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node *root){
        if (root == NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void levelOrder(Node *root){
        if (root == NULL)
            return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
};
int main(){
    BinaryTree tree;
    cout << "Create Binary Tree" << endl;
    tree.root = tree.createTree();
    cout << "\nInorder Traversal: ";
    tree.inorder(tree.root);
    cout << "\nPreorder Traversal: ";
    tree.preorder(tree.root);
    cout << "\nPostorder Traversal: ";
    tree.postorder(tree.root);
    cout << "\nLevel Order Traversal: ";
    tree.levelOrder(tree.root);
    cout << endl;
    return 0;
}