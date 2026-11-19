
// Hash Table using Separate Chaining (Without Probing)
// for k mod 10

#include <iostream>
using namespace std;

const int SIZE = 10;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// HashTable class
class HashTable {
private:
    Node* table[SIZE];       // It creates an array of 10 pointers.

    // Hash function
    int hashFunction(int key) {      // Converts a given key into a valid array index.
        return key % SIZE;
    }

public:

    // Constructor
    HashTable() {
        for(int i = 0; i < SIZE; i++) {    // initially blank part of array pointing towards null
            table[i] = NULL;
        }
    }

    // Insert operation function
    void insert(int key) {

        int index = hashFunction(key);

        Node* newNode = new Node(key);  // object creation

        // Insert node at beginning of linked list
        newNode->next = table[index];    // next pointer of new node now stores the address of prev node
        table[index] = newNode;       // update new Node

        cout << key << " inserted at index " << index << endl;
    }

    // Search operation
    bool search(int key) {

        int index = hashFunction(key);

        Node* temp = table[index];   // This pointer starts at the first node of the linked list.

        while(temp != NULL) {  //Traverse the linked list

            if(temp->data == key) {
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    // Display operation
    void display() {

        for(int i = 0; i < SIZE; i++) {

            cout << i << " : ";

            Node* temp = table[i];   // Starts traversing the linked list at the current index.

            while(temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
    }

};

// Main function
int main() {

    HashTable ht;

    ht.insert(25);
    ht.insert(35);
    ht.insert(45);
    ht.insert(12);
    ht.insert(22);

    cout << "\nHash Table:\n";
    ht.display();

    int key = 35;

    if(ht.search(key)) {
        cout << "\n" << key << " Found!";
    }
    else {
        cout << "\n" << key << " Not Found!";
    }

    return 0;
}
