#include <iostream>
#include <string>
using namespace std;
class Book {
    private:
        string title;
        int copiesAvailable;
    public:
        void input(){
            cout << "Enter book title:" << endl;
            cin >> title;
            cout << "Enter copies available:" << endl;
            cin >> copiesAvailable;
        }
        Book operator--(){
            if(copiesAvailable>0){
                copiesAvailable--;
            }
            return *this;
        }
        Book operator++(){
            copiesAvailable++;
            return *this;
        }
        bool operator==(const Book&other)const{
            return this->title==other.title;
        }
        void display()const{
            cout << "Title:" << title << " Copies:" << copiesAvailable << endl;
        }
};
int main(){
    Book b1;
    Book b2;
    b1.input();
    b2.input();
    if(b1==b2){
        cout << "Books are the same." << endl;
    }else{
        cout << "Books are different." << endl;
    }
    --b1;
    cout << "After issuing one copy of book 1:" << endl;
    b1.display();
    ++b1;
    cout << "After returning one copy of book 1:" << endl;
    b1.display();
    return 0;
}