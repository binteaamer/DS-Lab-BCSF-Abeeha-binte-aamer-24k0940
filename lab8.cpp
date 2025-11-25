//i learnt this code for prepping for dsa thoery exam therefore its properly commmented and has extra functions

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
        left = right = nullptr;}};

// INSERT
node* insertbst(node* root, int key) {
    if(root == nullptr) return new node(key);

    if(key > root->data)
        root->right = insertbst(root->right, key);
    else if(key < root->data)
        root->left = insertbst(root->left, key);

    return root;}

// INORDER
void inorder(node* root) {
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);}

// PREORDER
void preorder(node* root) {
    if(root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);}

// POSTORDER
void postorder(node* root) {
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";}

// LEVEL ORDER
void levelorder(node* root) {
    if(root == nullptr) return;

    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node* curr = q.front();
        q.pop();

        cout << curr->data << " ";

        if(curr->left != nullptr)
            q.push(curr->left);
        if(curr->right != nullptr)
            q.push(curr->right);
    }}

// SEARCH
bool searchinbst(node* root, int key) {
    if(root == nullptr) return false;
    if(root->data == key) return true;

    if(key > root->data)
        return searchinbst(root->right, key);

    return searchinbst(root->left, key);}

// MINIMUM NODE
node* minBST(node* root) {
    while(root != nullptr && root->left != nullptr)
        root = root->left;
    return root;
}

// DELETE
node* deletebst(node* root, int key) {
    if(root == nullptr) return root;

    if(key < root->data) {
     root->left = deletebst(root->left, key);}
    else if(key > root->data) {
     root->right = deletebst(root->right, key); }
    else {
        // CASE 1: NO CHILD
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr; }
        // CASE 2: ONE CHILD
        else if(root->left == nullptr) {
        node* temp = root->right;
        delete root;
        return temp; }
        else if(root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp; }
        // CASE 3: TWO CHILDREN
        node* temp = minBST(root->right);
        root->data = temp->data;
        root->right = deletebst(root->right, temp->data);  }
    return root;}
// HEIGHT
int height(node* root) {
    if(root == nullptr) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;}

// TOTAL NODES
int totalnodes(node* root) {
    if(root == nullptr) return 0;
    return 1 + totalnodes(root->left) + totalnodes(root->right);}

// CHECK FULL BINARY TREE
bool isfull(node* root) {
  if(root == nullptr) return true;}
    // leaf node
    if(root->left == nullptr && root->right == nullptr)
        return true;

    // both children present
    if(root->left != nullptr && root->right != nullptr)
        return isfull(root->left) && isfull(root->right);
    return false;
}

// CHECK COMPLETE BINARY TREE
bool iscomplete(node* root) {
    if(root == nullptr) return true;

    queue<node*> q;
    q.push(root);
    bool nullfound = false;

    while(!q.empty()) {
        node* curr = q.front();
        q.pop();

        if(curr == nullptr) {
            nullfound = true;
        }
        else {
            if(nullfound) return false;
            q.push(curr->left);
            q.push(curr->right);
        }  }
    return true;
}
// MAIN
int main() {
    node* root = nullptr;

    root = insertbst(root, 50);
    insertbst(root, 30);
    insertbst(root, 70);
    insertbst(root, 20);
    insertbst(root, 40);
    insertbst(root, 60);
    insertbst(root, 80);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Level Order: ";
    levelorder(root);
    cout << endl;

    cout << "Search 40: " << (searchinbst(root, 40) ? "Found" : "Not Found") << endl;

    cout << "Height: " << height(root) << endl;

    cout << "Total Nodes: " << totalnodes(root) << endl;

    cout << "Is Full: " << (isfull(root) ? "Yes" : "No") << endl;
    cout << "Is Complete: " << (iscomplete(root) ? "Yes" : "No") << endl;

    return 0;
}

