#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;
class Polynomial {
public:
    vector<double> coeffs;
    Polynomial() {}
    Polynomial(vector<double> c) : coeffs(c) {
        while (!coeffs.empty() && fabs(coeffs.back()) < 1e-9)
            coeffs.pop_back();
    }
    bool isZero() const {
        return coeffs.empty();
    }
    int degree() const {
        if (isZero()) return -1;
        return coeffs.size() - 1;
    }
    double coeff(int d) const {
        if (d < 0 || d >= coeffs.size()) return 0.0;
        return coeffs[d];
    }
    Polynomial divide(const Polynomial& divisor) const {
        if (divisor.isZero()) {
            throw runtime_error("Division by zero polynomial");
        }
        Polynomial dividend = *this;
        Polynomial quotient;
        while (dividend.degree() >= divisor.degree() && !dividend.isZero()) {
            double c = dividend.coeff(dividend.degree()) / divisor.coeff(divisor.degree());
            int d = dividend.degree() - divisor.degree();
            Polynomial term;
            term.coeffs.resize(d + 1, 0.0);
            term.coeffs[d] = c;
            if (quotient.coeffs.size() < term.coeffs.size())
                quotient.coeffs.resize(term.coeffs.size(), 0.0);
            for (size_t i = 0; i < term.coeffs.size(); i++)
                quotient.coeffs[i] += term.coeffs[i];
            Polynomial sub;
            sub.coeffs.resize(term.coeffs.size() + divisor.coeffs.size() - 1, 0.0);
            for (size_t i = 0; i < term.coeffs.size(); i++)
                for (size_t j = 0; j < divisor.coeffs.size(); j++)
                    sub.coeffs[i + j] += term.coeffs[i] * divisor.coeffs[j];
            if (dividend.coeffs.size() < sub.coeffs.size())
                dividend.coeffs.resize(sub.coeffs.size(), 0.0);
            for (size_t i = 0; i < sub.coeffs.size(); i++)
                dividend.coeffs[i] -= sub.coeffs[i];
            while (!dividend.coeffs.empty() && fabs(dividend.coeffs.back()) < 1e-9)
                dividend.coeffs.pop_back();
        }
        return quotient;
    }
};
int main() {
    Polynomial p1({1, 2, 1});
    Polynomial p2({1, 1});
    try {
        Polynomial q = p1.divide(p2);
        cout << "Quotient coefficients (from x^0 to x^n): ";
        for (double c : q.coeffs) cout << c << " ";
        cout << endl;
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    Polynomial zero({0});
    try {
        Polynomial q = p1.divide(zero);
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}