#include <iostream>
using namespace std;

class CircularQueue {
public:
    int arr[50];
    int front, rear, size;

    CircularQueue(int n = 50) {
        size = n;
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % size == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        cout << value << " enqueued" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << arr[front] << " dequeued" << endl;
        if (front == rear) {
            
            front = rear = -1;
        } else {
            front = (front + 1) % size;
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
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n Circular Queue Menu \n";
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