#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};
class List {
private:
    Node* head;
public:
    List() {
        head = NULL;
    }
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << val << endl;
            return;
        }
        Node* current = head;
        Node* previous = NULL;
        while (current != NULL && current->data != val) {
            previous = current;
            current = current->next;
        }
        if (current == NULL) {
            cout << "Value " << val << " not found." << endl;
            return;
        }
        previous->next = current->next;
        delete current;
    }
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    List myList;
    int choice, value;
    while (true) {
        cout << "Enter 1 to Insert at end, 2 to Delete node by value, 3 to Display list, 4 to Exit" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << "Enter value to insert: ";
            cin >> value;
            myList.insertEnd(value);
        } else if (choice == 2) {
            cout << "Enter value to delete: ";
            cin >> value;
            myList.deleteNode(value);
        } else if (choice == 3) {
            myList.display();
        } else if (choice == 4) {
            cout << "Exiting." << endl;
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}