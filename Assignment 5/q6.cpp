#include <iostream>
using namespace std;
class Animal {
    public:
        void describe() {
            cout << "I am an Animal." << endl;
        }
};
class Mammal : public Animal {
    public:
        void describe() {
            cout << "I am a Mammal." << endl;
        }
};
class Dog : public Mammal {
    public:
        void describe() {
            cout << "I am a Dog." << endl;
        }
};
int main() {
    Dog myDog;
    cout << "Calling Dog's describe function..." << endl;
    myDog.describe();
    cout << "Demonstrating Multilevel Inheritance: " << endl;
    myDog.Animal::describe();
    myDog.Mammal::describe();
    return 0;
}