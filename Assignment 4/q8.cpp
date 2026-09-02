#include <iostream>
using namespace std;
class Polynomial{
    private:
        int degree;
        int coeffs[10];
    public:
        void input() {
            cout << "Enter polynomial degree:" << endl;
            cin >> degree;
            for(int i=0;i<=degree;i++){
                cout << "Enter coefficient for x^" << i << ":" << endl;
                cin >> coeffs[i];
            }
        }
        bool operator==(const Polynomial&other) const {
            if(this->degree!=other.degree)return false;
            for(int i=0;i<=this->degree;i++){
                if(this->coeffs[i]!=other.coeffs[i]) {
                    return false;
                }
            }
            return true;
        }
        bool operator<(const Polynomial&other) const {
            return this->degree<other.degree;
        }
        void display() const {
            for(int i=degree;i>=0;i--) {
                cout << coeffs[i] << "x^" << i;
                if(i>0) {
                    cout << "+";
                }
            }
            cout << endl;
        }
};
int main(){
    Polynomial p1;
    Polynomial p2;
    p1.input();
    p2.input();
    cout << "Polynomial 1:" << endl;
    p1.display();
    cout << "Polynomial 2:" << endl;
    p2.display();
    if (p1==p2) {
        cout << "Polynomials are identical." << endl;
    } else {
        cout << "Polynomials are not identical." << endl;
    }
    if (p1<p2) {
        cout << "Polynomial 1 has a lesser degree." << endl;
    } else {
        cout << "Polynomial 1 does not have a lesser degree." << endl;
    }
    return 0;
}