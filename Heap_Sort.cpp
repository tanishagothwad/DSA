
#include <iostream>
using namespace std;

class HeapSort {
    int arr[100];
    int n;

public:
    void accept() {
        cout << "Enter number of players: ";
        cin >> n;

        cout << "Enter player scores:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    // Max Heapify
    void maxHeapify(int a[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] > a[largest])
            largest = left;

        if (right < n && a[right] > a[largest])
            largest = right;

        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify(a, n, largest);
        }
    }

    // Min Heapify
    void minHeapify(int a[], int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] < a[smallest])
            smallest = left;

        if (right < n && a[right] < a[smallest])
            smallest = right;

        if (smallest != i) {
            swap(a[i], a[smallest]);
            minHeapify(a, n, smallest);
        }
    }

    // Heap Sort using Max Heap
    void maxHeapSort() {
        int a[100];

        for (int i = 0; i < n; i++)
            a[i] = arr[i];

        // Build Max Heap
        for (int i = n / 2 - 1; i >= 0; i--)
            maxHeapify(a, n, i);

        // Extract elements
        for (int i = n - 1; i > 0; i--) {
            swap(a[0], a[i]);
            maxHeapify(a, i, 0);
        }

        cout << "\nScores in Ascending Order:\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << endl;
    }

    // Heap Sort using Min Heap
    void minHeapSort() {
        int a[100];

        for (int i = 0; i < n; i++)
            a[i] = arr[i];

        // Build Min Heap
        for (int i = n / 2 - 1; i >= 0; i--)
            minHeapify(a, n, i);

        // Extract elements
        for (int i = n - 1; i > 0; i--) {
            swap(a[0], a[i]);
            minHeapify(a, i, 0);
        }

        cout << "\nScores in Descending Order:\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";

        cout << endl;
    }
};

int main() {
    HeapSort h;
    int choice;

    h.accept();

    do {
        cout << "\n===== ONLINE LEADERBOARD =====\n";
        cout << "1. Max Heap (Ascending Order)\n";
        cout << "2. Min Heap (Descending Order)\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            h.maxHeapSort();
            break;

        case 2:
            h.minHeapSort();
            break;

        case 3:
            cout << "Exiting Leaderboard System...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
