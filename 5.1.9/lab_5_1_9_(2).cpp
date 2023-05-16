#include <iostream>
using namespace std;

class Square {
private:
    double side;  // Hidden member variable

public:
    void set_side(double new_side) {
        if (new_side >= 0) {
            side = new_side;
        }
    }

    void print() {
        double area = side * side;
        cout << "Square with side " << side << " has area " << area << endl;
    }
};

int main() {
    Square square;
    square.set_side(5.0);
    square.print();

    square.set_side(-2.0);  // Ignored since argument is less than 0
    square.print();

    return 0;
}
