#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator) {
        int gcd = calculateGCD(abs(numerator), abs(denominator));
        this->numerator = numerator / gcd;
        this->denominator = denominator / gcd;
    }

    string toString() {
        if (denominator == 1) {
            return to_string(numerator);
        } else if (numerator == 0) {
            return "0";
        } else {
            int wholePart = numerator / denominator;
            int remainder = abs(numerator) % abs(denominator);
            string result;

            if (numerator < 0 ^ denominator < 0) {
                result += "-";
            }

            if (wholePart != 0) {
                result += to_string(abs(wholePart)) + " ";
            }

            result += to_string(remainder) + "/" + to_string(abs(denominator));
            return result;
        }
    }

    double toDouble() {
        return static_cast<double>(numerator) / denominator;
    }

private:
    int numerator;
    int denominator;

    int calculateGCD(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return calculateGCD(b, a % b);
        }
    }
};

int main() {
    int num, den;
    cout << "Enter a fraction in the form [numerator] / [denominator]: ";
    cin >> num;
    cin.ignore();  // Ignore the space between numerator and denominator
    cin >> den;

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

    return 0;
}


