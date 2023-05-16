#include <iostream>
#include <string>
using namespace std;

class Member {
public:
    int id;
    string name;
    int subscriptionMonths;

    Member() {
        id = 0;
        name = "";
        subscriptionMonths = 0;
    }

    void create(int memberId, const string& memberName) {
        if (id == 0) {
            id = memberId;
            name = memberName;
            cout << "Member " << id << " created: " << name << ", subscription valid for " << subscriptionMonths << " months" << endl;
        } else {
            cout << "Cannot perform this operation. Member " << id << " already exists." << endl;
        }
    }

    void extend(int n) {
        if (id == 0) {
            cout << "Cannot perform this operation. Member does not exist." << endl;
        } else if (n > 0) {
            subscriptionMonths += n;
            cout << "Member " << id << " subscription extended by " << n << " months" << endl;
        } else {
            cout << "Cannot perform this operation. Invalid number of months to extend." << endl;
        }
    }

    void cancel() {
        if (id == 0) {
            cout << "Cannot perform this operation. Member does not exist." << endl;
        } else {
            subscriptionMonths = 0;
            cout << "Member " << id << " subscription canceled" << endl;
        }
    }

    void remove() {
        if (id == 0) {
            cout << "Cannot perform this operation. Member does not exist." << endl;
        } else {
            id = 0;
            name = "";
            subscriptionMonths = 0;
            cout << "Member removed" << endl;
        }
    }

    int getId() {
        return id;
    }

    const string& getName() {
        return name;
    }

    int getSubscriptionMonths() {
        return subscriptionMonths;
    }
};

int main() {
    const int MAX_MEMBERS = 10;
    Member members[MAX_MEMBERS];

    string command;
    while (command != "quit") {
        cout << "Enter a command: ";
        cin >> command;

        if (command == "create") {
            int id;
            string name;
            cin >> id >> name;

            if (id < 1 || id > MAX_MEMBERS) {
                cout << "Invalid member ID. Member ID must be between 1 and " << MAX_MEMBERS << endl;
                continue;
            }

            members[id - 1].create(id, name);
        } else if (command == "delete") {
            int id;
            cin >> id;

            if (id < 1 || id > MAX_MEMBERS) {
                cout << "Invalid member ID. Member ID must be between 1 and " << MAX_MEMBERS << endl;
                continue;
            }

            members[id - 1].remove();
        } else if (command == "extend") {
            int id, n;
            cin >> id >> n;

            if (id < 1 || id > MAX_MEMBERS) {
                cout << "Invalid member ID. Member ID must be between 1 and " << MAX_MEMBERS << endl;
                continue;
            }

            members[id - 1].extend(n);
        } else if (command == "cancel") {
            int id;
            cin >> id;

            if (id < 1 || id > MAX_MEMBERS) {
                cout << "Invalid member ID. Member ID must be between 1 and " << MAX_MEMBERS << endl;
                continue;
            }

