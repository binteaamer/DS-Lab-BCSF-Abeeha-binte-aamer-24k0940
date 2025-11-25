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

void findKthSmallest(node* root, int& k, int& result) {
if (root == nullptr || k <= 0) return;
findKthSmallest(root->left, k, result);
k--;
if (k == 0) {
result = root->data;
return;
}
findKthSmallest(root->right, k, result);
}

void findKthLargest(node* root, int& k, int& result) {
if (root == nullptr || k <= 0) return;
findKthLargest(root->right, k, result);
k--;
if (k == 0) {
result = root->data;
return;
}
findKthLargest(root->left, k, result);
}

void printHeights(node* root) {
if (root == nullptr) return;
cout << "Node " << root->data << ": left height=" << height(root->left) << ", right height=" << height(root->right) << endl;
printHeights(root->left);
printHeights(root->right);
}

int main() {
node* root = nullptr;
int arr[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85};
for (int i = 0; i < 15; i++) {
root = insert(root, arr[i]);
}

int k1 = 3, k2 = 4;
int small, large;
int ktemp1 = k1, ktemp2 = k2;

findKthSmallest(root, ktemp1, small);
findKthLargest(root, ktemp2, large);

cout << k1 << "rd smallest: " << small << endl;
cout << k2 << "th largest: " << large << endl;
cout << "Heights:" << endl;
printHeights(root);

return 0;
}
