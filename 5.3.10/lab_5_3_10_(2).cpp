#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool addReservation(int n);
    bool cancelReservation(int n);

private:
    int id;
    int capacity;
    int reserved;
    double maxReservationPercentage;
};

void FlightBooking::printStatus() {
    double percentage = static_cast<double>(reserved) / capacity * 100;
    cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << fixed << setprecision(2) << percentage << "%) seats taken" << endl;
}

bool FlightBooking::addReservation(int n) {
    int newReserved = reserved + n;
    double maxReservation = capacity * maxReservationPercentage;
    if (newReserved <= maxReservation && n >= 0) {
        reserved = newReserved;
        return true;
    } else {
        return false;
    }
}

bool FlightBooking::cancelReservation(int n) {
    int newReserved = reserved - n;
    if (newReserved >= 0 && n >= 0) {
        reserved = newReserved;
        return true;
    } else {
        return false;
    }
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
    this->id = id;
    this->capacity = capacity;
    this->reserved = reserved;

    if (this->reserved < 0) {
        this->reserved = 0;
    }

    this->maxReservationPercentage = 1.05; // Allowing 105% of capacity
}

int main() {
    int reserved = 0, capacity = 0;
    string command;
    int quantity;

    cout << "Provide flight capacity: ";
    cin >> capacity;
    cout << "Provide number of reserved seats: ";
    cin >> reserved;

    FlightBooking booking(1, capacity, reserved);

    while (true) {
        cout << "Enter a command (add/cancel/quit): ";
        cin >> command;

        if (command == "add") {
            cin >> quantity;
            if (booking.addReservation(quantity)) {
                cout << "Reservations added successfully." << endl;
                booking.printStatus();
            } else {
                cout << "Cannot perform this operation" << endl;
            }
        } else if (command == "cancel") {
            cin >> quantity;
            if (booking.cancelReservation(quantity)) {
                cout << "Reservations canceled successfully." << endl;
                booking.printStatus();
            } else {
                cout << "Cannot perform this operation" << endl;
            }
        } else if (command == "quit") {
            break;
        } else {
            cout << "Invalid command. Try again." << endl;
        }
    }

    return 0;
}
