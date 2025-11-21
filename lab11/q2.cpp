//task 2 dictionary 

#include <iostream>
using namespace std;

struct Node {
    string key;
    Node* next;
    Node(string k) {
        key = k;
        next = NULL;
    }
};

class Dictionary {
private:
    Node* table[100];   // hash table size = 100

    // ASCII SUM hash function
    int hashFunction(string word) {
        int sum = 0;
        for (char c : word)
            sum += int(c);
        return sum % 100;
    }

public:
    Dictionary() {
        for (int i = 0; i < 100; i++)
            table[i] = NULL;
    }

    // a) Add Record
    void Add_Record(string word) {
        int index = hashFunction(word);
        Node* newNode = new Node(word);

        // insert at head (separate chaining)
        newNode->next = table[index];
        table[index] = newNode;
    }

    // b) Search
    void Word_Search(string word) {
        int index = hashFunction(word);
        Node* temp = table[index];

        while (temp != NULL) {
            if (temp->key == word) {
                cout << "search key " << word << ": FOUND" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "ERROR: " << word << " not found!" << endl;
    }

    // Delete a word from dictionary
    void Delete_Word(string word) {
        int index = hashFunction(word);
        Node* temp = table[index];
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->key == word) {
                if (prev == NULL)
                    table[index] = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                cout << "key " << word << " deleted successfully!" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "ERROR: delete failed, " << word << " not found!" << endl;
    }

    // c) Print dictionary
    void Print_Dictionary() {
        for (int i = 0; i < 100; i++) {
            if (table[i] != NULL) {
                cout << "index " << i << ": (";
                Node* temp = table[i];
                while (temp != NULL) {
                    cout << temp->key;
                    if (temp->next != NULL) cout << ", ";
                    temp = temp->next;
                }
                cout << ")" << endl;
            }
        }
    }
};

int main() {
    Dictionary dict;

    dict.Add_Record("AB");
    dict.Add_Record("FASTNU");
    dict.Add_Record("CD");
    dict.Add_Record("CS");

    dict.Word_Search("AB");

    dict.Delete_Word("EF");  // EF not present

    dict.Print_Dictionary();

    return 0;
}
