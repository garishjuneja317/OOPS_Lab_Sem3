#include <iostream>
using namespace std;
const int memSize=10;
void display(int* memory) {
    cout << "Current Memory: " << endl << "[ ";
    for (int i=0; i<memSize; i++) {
        cout << *(memory+i) << " ";
    }
    cout << "]" << endl;
}
void allocate(int* mem, int size, int id) {
    int free=0;
    int* start=nullptr;
    for (int i=0; i<memSize; i++) {
        if (*(mem+i)==0) {
            if (free==0) {
                start=mem+i;
            }
            free++;
            if (free==size) {
                for (int j=0; j<size; j++) {
                    *(start+j)=id;
                }
                return;
            }
        } else {
            free=0;
        }
    }
    cout << "Allocation failed, not enough space." << endl;
}
void deallocate(int* mem, int id) {
    bool found=false;
    for (int i=0; i<memSize; i++) {
        if (*(mem+i) == id) {
            *(mem+i)=0;
            found=true;
        }
    }
    if (found) {
        cout << "Deallocated all memory for the specified ID." << endl;
    } else {
        cout << "ID " << id << " not found in memory." << endl;
    }
}
void compact(int* mem) {
    int* ptr = mem;
    for (int i=0; i<memSize; i++) {
        if (*(mem+i)!=0) {
            *ptr=*(mem+i);
            ptr++;
        }
    }
    while (ptr<mem+memSize) {
        *ptr=0;
        ptr++;
    }
}
int main() {
    int memory[memSize] = {0};
    int choice;
    while (true) {
        display(memory);
        cout << "Enter 1 for memory allocation, 2 for deallocation, 3 for Compact memory, and 4 for EXIT:" << endl;
        cin >> choice;
        bool breaking=false;
        int id;
        switch (choice) {
            case 1:
                int size;
                cout << "Enter the size of memory to be allocated:" << endl;
                cin >> size;
                cout << "Enter the ID:" << endl;
                cin >> id;
                allocate(memory, size, id);
                break;
            case 2:
                cout << "Enter id to deallocate" << endl;
                cin >> id;
                deallocate(memory, id);
                break;
            case 3:
                compact(memory);
                break;
            case 4:
                breaking=true;
                break;
            default:
                cout << "Invalid Input! Try Again" << endl;
        }
        if (breaking) {
            break;
        }
    }
    return 0;
}