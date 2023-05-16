#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
    string occupation;  // Additional member variable

    void print() {  // Member function to print person details
        cout << name << " is " << age << " years old and works as a " << occupation << endl;
    }
};

int main() {
    Person person;
    person.name = "Harry";
    person.age = 23;
    person.occupation = "Software Engineer";

    cout << "Meet " << person.name << endl;
    person.print();

    return 0;
}
