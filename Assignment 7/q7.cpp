#include <iostream>
using namespace std;
class Queue {
private:
    int arr[5];
    int front;
    int rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    void enqueue(int val) {
        if (rear == 4) {
            cout << "Queue Overflow! Cannot insert." << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = val;
    }
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }
        front++;
    }
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    int choice, value;
    while (true) {
        cout << "Enter 1 to Enqueue, 2 to Dequeue, 3 to Display, 4 to Exit." << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
        } else if (choice == 2) {
            q.dequeue();
        } else if (choice == 3) {
            q.display();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}