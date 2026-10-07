#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;
class DoubleBookingException : public exception {
private:
    string message;
public:
    DoubleBookingException(string patientName, string timeSlot) {
        message = "Patient " + patientName + " already has an appointment at " + timeSlot;
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};
class Doctor {
public:
    int id;
    string name;
    Doctor(int i, string n) : id(i), name(n) {}
};
class Patient {
public:
    int id;
    string name;
    Patient(int i, string n) : id(i), name(n) {}
};
class Appointment {
public:
    Doctor doctor;
    Patient patient;
    string timeSlot;
    Appointment(Doctor d, Patient p, string t) : doctor(d), patient(p), timeSlot(t) {}
};
class BookingSystem {
private:
    vector<Appointment> appointments;
public:
    void bookAppointment(Doctor doctor, Patient patient, string timeSlot) {
        for (const auto &appt : appointments) {
            if (appt.patient.id == patient.id && appt.timeSlot == timeSlot) {
                throw DoubleBookingException(patient.name, timeSlot);
            }
        }
        appointments.push_back(Appointment(doctor, patient, timeSlot));
        cout << "Appointment booked: Patient " << patient.name
             << " with Dr. " << doctor.name
             << " at " << timeSlot << endl;
    }
};
int main() {
    Doctor d1(1, "Smith");
    Doctor d2(2, "Jones");
    Patient p1(101, "Alice");
    Patient p2(102, "Bob");
    BookingSystem system;
    try {
        system.bookAppointment(d1, p1, "10:00 AM");
        system.bookAppointment(d2, p1, "10:00 AM"); // throws
    }
    catch (DoubleBookingException &e) {
        cout << "Exception: " << e.what() << endl;
    }
    system.bookAppointment(d1, p1, "11:00 AM");
    system.bookAppointment(d1, p2, "10:00 AM");
    return 0;
}