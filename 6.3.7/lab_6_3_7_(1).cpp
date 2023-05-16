#include <iostream>
#include <string>
using namespace std;

class IPAddress {
protected:
    string address;

public:
    IPAddress(const string& addr) : address(addr) {}

    IPAddress(const IPAddress& other) : address(other.address) {}

    virtual void print() const {
        cout << address << endl;
    }
};

class IPAddressChecked : public IPAddress {
private:
    bool correct;

public:
    IPAddressChecked(const string& addr, bool isCorrect)
        : IPAddress(addr), correct(isCorrect) {}

    IPAddressChecked(const IPAddressChecked& other)
        : IPAddress(other), correct(other.correct) {}

    void print() const override {
        IPAddress::print();
        cout << (correct ? " - Correct" : " - Not Correct") << endl;
    }
};

int main() {
    string ip1, ip2, ip3;

    cout << "Enter IP address 1: ";
    cin >> ip1;

    cout << "Enter IP address 2: ";
    cin >> ip2;

    cout << "Enter IP address 3: ";
    cin >> ip3;

    IPAddress ipAddr(ip1);
    IPAddressChecked ipChecked1(ip2, false);
    IPAddressChecked ipChecked2(ip3, true);

    cout << "IP addresses:" << endl;
    ipAddr.print();
    ipChecked1.print();
    ipChecked2.print();

    return 0;
}
