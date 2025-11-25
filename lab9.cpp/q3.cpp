//task3
//code

#include<iostream>
#include<queue>
using namespace std;

class node {
public:
int data;
node* left;
node* right;
int height;

node(int val) {
data = val;
left = right = nullptr;
height = 1;
}
};

int height(node* n) {
if (n == nullptr) return 0;
return n->height;
}

int max(int a, int b) {
return (a > b) ? a : b;
}

int getBalance(node* n) {
if (n == nullptr) return 0;
return height(n->left) - height(n->right);
}

node* rightRotate(node* y) {
node* x = y->left;
node* T2 = x->right;

x->right = y;
y->left = T2;

y->height = max(height(y->left), height(y->right)) + 1;
x->height = max(height(x->left), height(x->right)) + 1;

return x;
}

node* leftRotate(node* x) {
node* y = x->right;
node* T2 = y->left;

y->left = x;
x->right = T2;

x->height = max(height(x->left), height(x->right)) + 1;
y->height = max(height(y->left), height(y->right)) + 1;

return y;
}

node* insert(node* root, int key) {
if (root == nullptr) return new node(key);

if (key < root->data)
root->left = insert(root->left, key);
else if (key > root->data)
root->right = insert(root->right, key);
else
return root;

root->height = 1 + max(height(root->left), height(root->right));

int balance = getBalance(root);

if (balance > 1 && key < root->left->data)
return rightRotate(root);

if (balance < -1 && key > root->right->data)
return leftRotate(root);

if (balance > 1 && key > root->left->data) {
root->left = leftRotate(root->left);
return rightRotate(root);
}

if (balance < -1 && key < root->right->data) {
root->right = rightRotate(root->right);
return leftRotate(root);
}

return root;
}

void levelOrder(node* root) {
if (root == nullptr) return;
queue<node*> q;
q.push(root);
while (!q.empty()) {
node* curr = q.front();
q.pop();
cout << curr->data << " ";
if (curr->left != nullptr) q.push(curr->left);
if (curr->right != nullptr) q.push(curr->right);
}
}

int main() {
node* root = nullptr;
int arr[] = {10, 5, 15, 3, 7};
for (int i = 0; i < 5; i++) {
root = insert(root, arr[i]);
}
cout << "Original tree: ";
levelOrder(root);
cout << endl;

root = insert(root, 12);
cout << "After inserting 12: ";
levelOrder(root);
cout << endl;

cout << "Balance factors:" << endl;
queue<node*> q;
q.push(root);
while (!q.empty()) {
node* curr = q.front();
q.pop();
cout << "Node " << curr->data << ": " << getBalance(curr) << endl;
if (curr->left != nullptr) q.push(curr->left);
if (curr->right != nullptr) q.push(curr->right);
}

cout << "Tree height: " << height(root) << endl;

return 0;
}
