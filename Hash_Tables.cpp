
#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    // Linear Probing Without Replacement
    void insertWithoutReplacement(int key) {
        int index = hashFunction(key);

        if (table[index] == -1) {
            table[index] = key;
            return;
        }

        cout << "Collision occurred at index "
             << index << endl;

        int i = index;

        while (table[i] != -1) {
            i = (i + 1) % SIZE;

            if (i == index) {
                cout << "Hash Table is Full!\n";
                return;
            }
        }

        table[i] = key;
    }

    // Linear Probing With Replacement
    void insertWithReplacement(int key) {
        int index = hashFunction(key);

        if (table[index] == -1) {
            table[index] = key;
            return;
        }

        cout << "Collision occurred at index "
             << index << endl;

        // Check whether existing key belongs here
        if (hashFunction(table[index]) != index) {
            int oldKey = table[index];
            table[index] = key;

            int i = (index + 1) % SIZE;

            while (table[i] != -1) {
                i = (i + 1) % SIZE;

                if (i == index) {
                    cout << "Hash Table is Full!\n";
                    table[index] = oldKey;
                    return;
                }
            }

            table[i] = oldKey;
        }
        else {
            int i = (index + 1) % SIZE;

            while (table[i] != -1) {
                i = (i + 1) % SIZE;

                if (i == index) {
                    cout << "Hash Table is Full!\n";
                    return;
                }
            }

            table[i] = key;
        }
    }

    // Search for a vehicle
    void search(int key) {
        int index = hashFunction(key);
        int start = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                cout << "Vehicle " << key
                     << " found at parking slot "
                     << index << endl;
                return;
            }

            index = (index + 1) % SIZE;

            if (index == start)
                break;
        }

        cout << "Vehicle not found!\n";
    }

    // Display Hash Table
    void display() {
        cout << "\nParking Slot Allocation:\n";
        cout << "Slot\tVehicle Number\n";

        for (int i = 0; i < SIZE; i++) {
            cout << i << "\t";

            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];

            cout << endl;
        }
    }
};

int main() {
    HashTable h;
    int choice, key;

    do {
        cout << "\n===== PARKING SLOT ALLOCATION =====\n";
        cout << "1. Insert Without Replacement\n";
        cout << "2. Insert With Replacement\n";
        cout << "3. Search Vehicle\n";
        cout << "4. Display Parking Slots\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter vehicle number: ";
            cin >> key;
            h.insertWithoutReplacement(key);
            break;

        case 2:
            cout << "Enter vehicle number: ";
            cin >> key;
            h.insertWithReplacement(key);
            break;

        case 3:
            cout << "Enter vehicle number to search: ";
            cin >> key;
            h.search(key);
            break;

        case 4:
            h.display();
            break;

        case 5:
            cout << "Exiting Parking System...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
