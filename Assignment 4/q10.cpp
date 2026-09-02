#include <iostream>
#include <string>
using namespace std;
class Cart {
    private:
        string items[100];
        int count;
    public:
        void input() {
            cout << "Enter number of items in cart:" << endl;
            cin >> count;
            cout << "Enter the items:" << endl;
            for(int i=0;i<count;i++){
                cin >> items[i];
            }
        }
        Cart operator+(const Cart&other) const {
            Cart temp;
            temp.count=this->count+other.count;
            for(int i=0;i<this->count;i++) {
                temp.items[i]=this->items[i];
            }
            for(int i=0;i<other.count;i++) {
                temp.items[this->count+i]=other.items[i];
            }
            return temp;
        }
        string&operator[](int index) {
            return items[index];
        }
        void display() const {
            for(int i=0;i<count;i++){
                cout << items[i] << " ";
            }
            cout << endl;
        }
};
int main(){
    Cart c1;
    Cart c2;
    c1.input();
    c2.input();
    Cart c3=c1+c2;
    cout << "Merged Cart:" << endl;
    c3.display();
    cout << "Accessing item at index 0: " << c3[0] << endl;
    c3[0]="ModifiedItem";
    cout << "Cart after modifying index 0:" << endl;
    c3.display();
    return 0;
}