//task 2 from manual 
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
height = 1;}};

int height(node* n) {
if (n == nullptr) return 0;
return n->height;}

node* leftRotate(node* x) {
node* y = x->right;
node* T2 = y->left;

y->left = x;
x->right = T2;

x->height = max(height(x->left), height(x->right)) + 1;
y->height = max(height(y->left), height(y->right)) + 1;
return y;}
node* insert(node* root, int key) {
if (root == nullptr) return new node(key);
if (key < root->data)
root->left = insert(root->left, key);
else if (key > root->data)
root->right = insert(root->right, key);
else
return root;

root->height = 1 + max(height(root->left), height(root->right));
return root;  }

void levelOrder(node* root) {
if (root == nullptr) return;
queue<node*> q;
q.push(root);
while (!q.empty()) {
node* curr = q.front();
q.pop();
cout << curr->data << " ";
if (curr->left != nullptr) q.push(curr->left);
if (curr->right != nullptr) q.push(curr->right);}}

int main() {
node* root = nullptr;
int arr[] = {570, 30, 70, 20, 40, 60, 80};
for (int i = 0; i < 7; i++) {
root = insert(root, arr[i]);
}
cout << "Original tree: ";
levelOrder(root);
cout << endl;

root = insert(root, 55);
cout << "After inserting 55: ";
levelOrder(root);
cout << endl;

root = leftRotate(root);
cout << "After left rotation on root: ";
levelOrder(root);
cout << endl;
return 0;}
