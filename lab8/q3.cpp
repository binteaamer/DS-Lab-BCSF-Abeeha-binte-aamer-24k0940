//task 4 

//code 
#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    int data;
    node* right;
    node* left;
    node(int value) {
        data = value;
        left = right = nullptr;
    }};

node* insertbst(node* root, int key) {
 if(root == nullptr) return new node(key);

    if(key > root->data)
        root->right = insertbst(root->right, key);
    else if(key < root->data)
        root->left = insertbst(root->left, key);

    return root;}
void inorder(node* root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool searchinbst(node* root, int key) {
if(root == nullptr) return false;
if(root->data == key) return true;
  if(key > root->data)
  return searchinbst(root->right, key);
   return searchinbst(root->left, key);}

int main() {
    node* root = nullptr;
    root = insertbst(root, 50);
    insertbst(root, 30);
    insertbst(root, 70);
    insertbst(root, 20);
    insertbst(root, 40);
    insertbst(root, 60);
    insertbst(root, 80);

    cout << "current tree (inorder): ";
    inorder(root);
    cout << endl;

    int value;
    cout << "enter value to search: ";
    cin >> value;

    if(searchinbst(root, value)) {
        cout << value << " found in tree!" << endl; }
    else {
        cout << value << " not found. inserting into tree..." << endl;
        root = insertbst(root, value);
        cout << "new tree (inorder): ";
        inorder(root);
        cout << endl; }

    return 0;}
