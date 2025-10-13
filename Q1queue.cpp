#include <iostream>
using namespace std;

class Queue {
public:
    int arr[50];
    int front, rear, size;

    Queue(int n = 50) {
        size = n;
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == size - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
        } else {
            rear++;
            arr[rear] = value;
            cout << value << " enqueued" << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
        } else {
            cout << arr[front] << " dequeued" << endl;
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. IsEmpty\n6. IsFull\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;
            case 6:
                cout << (q.isFull() ? "Queue is full" : "Queue is not full") << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}