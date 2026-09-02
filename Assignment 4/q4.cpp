#include <iostream>
#include <string>
using namespace std;
class Item {
    private:
        string name;
        float price;
        int quantity;
    public:
        void input() {
            cout << "Enter item name:" << endl;
            cin >> name;
            cout << "Enter price:" << endl;
            cin >> price;
            cout << "Enter quantity:" << endl;
            cin >> quantity;
        }
        Item operator+(const Item&other) const {
            Item temp;
            temp.name=this->name;
            temp.price=this->price;
            temp.quantity=this->quantity+other.quantity;
            return temp;
        }
        float operator*() const {
            return price*quantity;
        }
        void displayQuantity() const {
            cout << quantity << endl;
        }
};
int main() {
    Item item1;
    Item item2;
    item1.input();
    item2.input();
    Item sum=item1+item2;
    cout << "Summed quantity: ";
    sum.displayQuantity();
    float cost1=*item1;
    float cost2=*item2;
    cout << "Total cost 1:" << cost1 << endl;
    cout << "Total cost 2:" << cost2 << endl;
    return 0;
}