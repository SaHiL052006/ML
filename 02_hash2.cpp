
// Hash Table using Linear Probing (With Probing)

#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTable {

private: 

    int table[SIZE];

    // Hash function
    int hashFunction(int key) {
        return key % SIZE;
    }

public:

    // Constructor
    HashTable() {
        for(int i = 0; i < SIZE; i++) {
            table[i] = -1;  //We use -1 to indicate that a particular position is empty.
        }
    }

    // Insert operation
    void insert(int key) {

        int index = hashFunction(key);

        // Linear probing
        for(int i = 0; i < SIZE; i++) {

            int newIndex = (index + i) % SIZE;  //This is the actual Linear Probing formula.

            // Check duplicate
            if(table[newIndex] == key) {
                cout << key << " already exists!" << endl;
                return;
            }

            // Find empty position
            if(table[newIndex] == -1) {

                table[newIndex] = key;

                cout << key << " inserted at index "
                     << newIndex << endl;

                return;
            }
        }
    }

    // Search operation
    bool search(int key) {

        int index = hashFunction(key);

        for(int i = 0; i < SIZE; i++) {

            int newIndex = (index + i) % SIZE; //Just like insertion, we check positions sequentially using Linear Probing.

            // Empty position means key is absent
            if(table[newIndex] == -1) {
                return false;
            }

            // Key found
            if(table[newIndex] == key) {
                return true;
            }
        }

        return false;  //If all positions are checked and the key is not found, return false.
    }

    // Display operation
    void display() {

        for(int i = 0; i < SIZE; i++) {

            cout << "Index " << i << " : ";

            if(table[i] == -1) {
                cout << "EMPTY";
            }
            else {
                cout << table[i];
            }
            cout << endl;
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

    int key = 45;

    if(ht.search(key)) {
        cout << "\n" << key << " Found!";
    }
    else {
        cout << "\n" << key << " Not Found!";
    }

    return 0;
}
