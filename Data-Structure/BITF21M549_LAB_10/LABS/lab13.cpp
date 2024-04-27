#include <iostream>
#include <string>
using namespace std;

class HashTable {
private:
    string *table;
    int size;
    int curSize;

public:
    HashTable(int size) : size(size), curSize(0) {
        table = new string[size];
        for (int i = 0; i < size; ++i) {
            table[i] = "EMPTY";
        }
    }

    ~HashTable() {
        delete[] table;
    }

    bool isEmpty() {
        return curSize == 0;
    }

    bool isFull() {
        return curSize == size;
    }

    double loadFactor() {
        return static_cast<double>(curSize) / size;
    }

    int hashFunction(string name) {
        int temp = 0;
        for (int i = 0; i < name.length(); ++i) {
            temp = temp + name[i];
        }
        return temp % size;
    }

    bool insert(string name) {
        if (isFull()) {
            return false; // Hash table is full
        }

        int index = hashFunction(name);
        int originalIndex = index;

        while (table[index] != "EMPTY") {
            index = (index + 1) % size; // Linear probing
            if (index == originalIndex) {
                return false; // Unable to find an empty slot
            }
        }

        table[index] = name;
        curSize++;
        return true;
    }

    bool search(string name) {
        int index = hashFunction(name);
        int originalIndex = index;

        while (table[index] != name && table[index] != "EMPTY") {
            index = (index + 1) % size; // Linear probing
            if (index == originalIndex) {
                return false; // Unable to find the name
            }
        }

        return table[index] == name;
    }

    bool remove(string name) {
        int index = hashFunction(name);
        int originalIndex = index;

        while (table[index] != name && table[index] != "EMPTY") {
            index = (index + 1) % size; // Linear probing
            if (index == originalIndex) {
                return false; // Unable to find the name
            }
        }

        if (table[index] == name) {
            table[index] = "EMPTY";
            curSize--;
            return true;
        }

        return false; // Name not found
    }

    void display() {
        for (int i = 0; i < size; ++i) {
            cout << "Index " << i << ": " << table[i] << endl;
        }
    }
};

void menu(HashTable &hashTable) {
    int choice;
    string name;

    do {
        cout << "Options:\n";
        cout << "1. Insert a name\n";
        cout << "2. Search for a name\n";
        cout << "3. Remove a name\n";
        cout << "4. Display the table\n";
        cout << "5. Display the load factor of the table\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the name to insert: ";
            cin >> name;
            if (hashTable.insert(name)) {
                cout << "Name inserted successfully!\n";
            } else {
                cout << "Hash table is full. Unable to insert.\n";
            }
        } else if (choice == 2) {
            cout << "Enter the name to search: ";
            cin >> name;
            if (hashTable.search(name)) {
                cout << "Name found in the hash table.\n";
            } else {
                cout << "Name not found in the hash table.\n";
            }
        } else if (choice == 3) {
            cout << "Enter the name to remove: ";
            cin >> name;
            if (hashTable.remove(name)) {
                cout << "Name removed successfully!\n";
            } else {
                cout << "Name not found in the hash table.\n";
            }
        } else if (choice == 4) {
            cout << "Displaying the table:\n";
            hashTable.display();
        } else if (choice == 5) {
            cout << "Load factor of the table: " << hashTable.loadFactor() << endl;
        } else if (choice == 6) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);
}

int main() {
    int tableSize;
    cout << "Enter the size of the hash table: ";
    cin >> tableSize;

    HashTable hashTable(tableSize);
    menu(hashTable);

    return 0;
}
