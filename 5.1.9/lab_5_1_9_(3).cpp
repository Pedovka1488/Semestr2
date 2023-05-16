#include <iostream>
using namespace std;

class AdHocSquare {
public:
    AdHocSquare(double side) {
        set_side(side);
    }

    void set_side(double side) {
        if (side >= 0) {
            this->side = side;
        }
    }

    double get_area() {
        return side * side;
    }

private:
    double side;
};

class LazySquare {
public:
    LazySquare(double side) {
        set_side(side);
    }

    void set_side(double side) {
        if (side >= 0) {
            this->side = side;
            side_changed = true;
        }
    }

    double get_area() {
        if (side_changed) {
            area = side * side;
            side_changed = false;
        }
        return area;
    }

private:
    double side;
    double area;
    bool side_changed;
};

int main() {
    AdHocSquare adHocSquare(5.0);
    cout << "AdHocSquare area: " << adHocSquare.get_area() << endl;

    LazySquare lazySquare(5.0);
    cout << "LazySquare area: " << lazySquare.get_area() << endl;

    lazySquare.set_side(3.0);
    cout << "LazySquare area: " << lazySquare.get_area() << endl;

    return 0;
}
