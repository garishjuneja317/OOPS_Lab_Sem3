#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
class Product {
public:
    int id;
    string name;
    double price;
};
int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;
    Product* products = new Product[n];
    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << endl;
        cout << "Enter ID: ";
        cin >> products[i].id;
        cout << "Enter Name: ";
        cin >> products[i].name;
        cout << "Enter Price: ";
        cin >> products[i].price;
    }
    ofstream outFile("products.txt");
    for (int i = 0; i < n; i++) {
        outFile << products[i].id << " " << products[i].name << " " << products[i].price << endl;
    }
    outFile.close();
    cout << "\nProduct Details:" << endl;
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" << endl;
    ifstream inFile("products.txt");
    Product temp;
    while (inFile >> temp.id >> temp.name >> temp.price) {
        cout << left << setw(10) << temp.id << setw(20) << temp.name << setw(10) << temp.price << endl;
    }
    inFile.close();
    delete[] products;
    return 0;
}