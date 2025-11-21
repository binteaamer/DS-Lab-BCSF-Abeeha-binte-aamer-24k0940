//code 
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;};

void insert(Node*& head, string name, int score) {
Node* newNode = new Node{name, score, nullptr};

 if (!head) {
    head = newNode;
    return;}
  
    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}
void display(Node* head) {
while (head) {
  cout << head->name << " - " << head->score << endl;
  head = head->next;}
}
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
      if (arr[i] > mx)
        mx = arr[i];
    return mx;}
void countingSort(int arr[], string names[], int n, int exp) {
    int output[n];
    string outputNames[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
  
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        outputNames[count[digit] - 1] = names[i];
        count[digit]--;    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
        names[i] = outputNames[i];
    }}
void radixSort(int arr[], string names[], int n) {
    int mx = getMax(arr, n);
    for (int exp = 1; mx / exp > 0; exp *= 10)
        countingSort(arr, names, n, exp);}
Node* rebuildList(int arr[], string names[], int n) {
    Node* head = nullptr;
    for (int i = 0; i < n; i++)
        insert(head, names[i], arr[i]);
    return head;
}

int main() {
    Node* head = nullptr;
    insert(head, "Ali", 88);
    insert(head, "Sara", 93);
    insert(head, "Usman", 75);
    insert(head, "Ayesha", 92);
    insert(head, "Hina", 60);

    cout << "Original List:\n";
    display(head);
    int n = 0;
    Node* temp = head;
    while (temp) {
        n++;
        temp = temp->next;
    }
    int scores[n];
    string names[n];

    temp = head;
    for (int i = 0; i < n; i++) {
        names[i] = temp->name;
        scores[i] = temp->score;
        temp = temp->next;}
    radixSort(scores, names, n);
    head = rebuildList(scores, names, n);
    cout << "\nSorted List (Ascending by Score):\n";
    display(head);
    return 0;
}
