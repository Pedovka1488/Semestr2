#include <iostream>
#include <string>
using namespace std;

class Flight {
public:
    int id;
    int capacity;
    int reservations;

    Flight() {
        id = 0;
        capacity = 0;
        reservations = 0;
    }

    void create(int flightId, int flightCapacity) {
        if (id == 0) {
            id = flightId;
            capacity = flightCapacity;
            cout << "Flight " << id << " created with capacity " << capacity << endl;
        } else {
            cout << "Cannot perform this operation. Flight " << id << " already exists." << endl;
        }
    }

    void cancel(int n) {
        if (id == 0) {
            cout << "Cannot perform this operation. Flight does not exist." << endl;
        } else if (n <= reservations) {
            reservations -= n;
            cout << n << " reservations canceled from Flight " << id << endl;
        } else {
            cout << "Cannot perform this operation. Insufficient reservations to cancel." << endl;
        }
    }

    void add(int n) {
        if (id == 0) {
            cout << "Cannot perform this operation. Flight does not exist." << endl;
        } else if (n <= capacity - reservations) {
            reservations += n;
            cout << n << " reservations added to Flight " << id << endl;
        } else {
            cout << "Cannot perform this operation. Insufficient capacity to add reservations." << endl;
        }
    }

    void remove() {
        if (id == 0) {
            cout << "Cannot perform this operation. Flight does not exist." << endl;
        } else {
            id = 0;
            capacity = 0;
            reservations = 0;
            cout << "Flight " << id << " removed" << endl;
        }
    }

    int getId() {
        return id;
    }
};

int main() {
    const int MAX_FLIGHTS = 10;
    Flight flights[MAX_FLIGHTS];

    string command;
    while (command != "quit") {
        cout << "Enter a command: ";
        cin >> command;

        if (command == "create") {
            int id, capacity;
            cin >> id >> capacity;

            if (id < 1 || id > MAX_FLIGHTS) {
                cout << "Invalid flight ID. Flight ID must be between 1 and " << MAX_FLIGHTS << endl;
                continue;
            }

            flights[id - 1].create(id, capacity);
        } else if (command == "delete") {
            int id;
            cin >> id;

            if (id < 1 || id > MAX_FLIGHTS) {
                cout << "Invalid flight ID. Flight ID must be between 1 and " << MAX_FLIGHTS << endl;
                continue;
            }

            flights[id - 1].remove();
        } else if (command == "add") {
            int id, n;
            cin >> id >> n;

            if (id < 1 || id > MAX_FLIGHTS) {
                cout << "Invalid flight ID. Flight ID must be between 1 and " << MAX_FLIGHTS << endl;
                continue;
            }

            flights[id - 1].add(n);
        } else if (command == "cancel") {
            int id, n;
            cin >> id >> n;

            if (id < 1 || id > MAX_FLIGHTS) {
                cout << "Invalid flight ID. Flight ID must be between 1 and " << MAX_FLIGHTS << endl;
