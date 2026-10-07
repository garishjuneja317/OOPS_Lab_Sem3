#include <iostream>
#include <exception>
#include <string>
using namespace std;
class OverbookingException : public exception {
private:
    string message;
    int availableSeats;
public:
    OverbookingException(int available) {
        availableSeats = available;
        message = "Not enough seats available.";
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
    int getAvailableSeats() const {
        return availableSeats;
    }
};
class Flight {
private:
    int totalSeats;
    int bookedSeats;
public:
    Flight(int total) {
        totalSeats = total;
        bookedSeats = 0;
    }
    int availableSeats() {
        return totalSeats - bookedSeats;
    }
    void bookSeats(int count) {
        if (count > availableSeats()) {
            throw OverbookingException(availableSeats());
        }
        bookedSeats += count;
        cout << count << " seat(s) booked successfully." << endl;
        cout << "Remaining seats: " << availableSeats() << endl;
    }
};
int main() {
    Flight flight(10);
    int seatsToBook;
    cout << "Enter number of seats to book: ";
    cin >> seatsToBook;
    try {
        flight.bookSeats(seatsToBook);
    }
    catch (OverbookingException &e) {
        cout << "Exception: " << e.what() << endl;
        cout << "Maximum seats available: " << e.getAvailableSeats() << endl;
    }
    return 0;
}