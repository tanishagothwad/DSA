
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class LibraryIndex {
    struct Book {
        int id;
        string title;
    };

    struct Index {
        int id;
        streampos position;
    };

    string dataFile = "books.dat";
    string indexFile = "index.dat";

public:

    // Insert Book Record
    void insertBook() {
        Book b;
        Index idx;

        cout << "Enter Book ID: ";
        cin >> b.id;
        cin.ignore();

        if (searchBook(b.id, false)) {
            cout << "Book ID already exists!\n";
            return;
        }

        cout << "Enter Book Title: ";
        getline(cin, b.title);

        fstream data(dataFile,
                     ios::in | ios::out | ios::binary);

        if (!data) {
            ofstream create(dataFile, ios::binary);
            create.close();

            data.open(dataFile,
                      ios::in | ios::out | ios::binary);
        }

        data.seekp(0, ios::end);

        idx.id = b.id;
        idx.position = data.tellp();

        int len = b.title.length();

        data.write(reinterpret_cast<char*>(&b.id),
                   sizeof(b.id));

        data.write(reinterpret_cast<char*>(&len),
                   sizeof(len));

        data.write(b.title.c_str(), len);

        data.close();

        // Insert into Index File
        ofstream index(indexFile,
                       ios::app | ios::binary);

        index.write(reinterpret_cast<char*>(&idx.id),
                    sizeof(idx.id));

        index.write(reinterpret_cast<char*>(&idx.position),
                    sizeof(idx.position));

        index.close();

        cout << "Book inserted successfully!\n";
    }

    // Search Book
    bool searchBook(int id, bool show = true) {
        ifstream index(indexFile, ios::binary);

        if (!index)
            return false;

        Index idx;

        while (index.read(reinterpret_cast<char*>(&idx.id),
                          sizeof(idx.id))) {

            if (!index.read(
                reinterpret_cast<char*>(&idx.position),
                sizeof(idx.position)))
                break;

            if (idx.id == id) {
                index.close();

                if (show) {
                    cout << "Book ID found in index!\n";
                    retrieveBook(idx.position);
                }

                return true;
            }
        }

        index.close();

        if (show)
            cout << "Book not found!\n";

        return false;
    }

    // Display Index Records
    void displayIndex() {
        ifstream index(indexFile, ios::binary);

        if (!index) {
            cout << "Index file is empty!\n";
            return;
        }

        Index idx;

        cout << "\nBook ID\tRecord Position\n";

        while (index.read(reinterpret_cast<char*>(&idx.id),
                          sizeof(idx.id))) {

            if (!index.read(
                reinterpret_cast<char*>(&idx.position),
                sizeof(idx.position)))
                break;

            cout << idx.id << "\t"
                 << static_cast<long long>(idx.position)
                 << endl;
        }

        index.close();
    }

    // Retrieve Book Record
    void retrieveBook(streampos position) {
        ifstream data(dataFile, ios::binary);

        if (!data) {
            cout << "Data file not found!\n";
            return;
        }

        data.seekg(position);

        Book b;
        int len;

        data.read(reinterpret_cast<char*>(&b.id),
                  sizeof(b.id));

        data.read(reinterpret_cast<char*>(&len),
                  sizeof(len));

        if (!data || len < 0 || len > 10000) {
            cout << "Invalid book record!\n";
            return;
        }

        b.title.resize(len);

        if (len > 0)
            data.read(&b.title[0], len);

        if (!data) {
            cout << "Unable to retrieve book!\n";
            return;
        }

        cout << "\nBook Record Details\n";
        cout << "Book ID: " << b.id << endl;
        cout << "Book Title: " << b.title << endl;

        data.close();
    }
};

int main() {
    LibraryIndex lib;
    int choice, id;

    do {
        cout << "\n===== LIBRARY INDEX MANAGEMENT =====\n";
        cout << "1. Insert Book Record\n";
        cout << "2. Display Index Records\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            lib.insertBook();
            break;

        case 2:
            lib.displayIndex();
            break;

        case 3:
            cout << "Enter Book ID to search: ";
            cin >> id;
            lib.searchBook(id);
            break;

        case 4:
            cout << "Exiting Library System...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
