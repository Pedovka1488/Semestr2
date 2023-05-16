#include <iostream>
#include <string>
using namespace std;

class ShopItemOrder {
public:
    ShopItemOrder(const string& name, double unitPrice, int quantity) {
        set_item(name, unitPrice, quantity);
    }

    void set_item(const string& name, double unitPrice, int quantity) {
        this->name = name;
        this->unitPrice = unitPrice;
        this->quantity = quantity;
    }

    string get_item_name() const {
        return name;
    }

    double get_unit_price() const {
        return unitPrice;
    }

    int get_quantity() const {
        return quantity;
    }

    double get_total_price() const {
        return unitPrice * quantity;
    }

    void print_order() const {
        cout << "Item: " << name << endl;
        cout << "Unit Price: $" << unitPrice << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Price: $" << get_total_price() << endl;
    }

private:
    string name;
    double unitPrice;
    int quantity;
};

int main() {
    ShopItemOrder itemOrder("Phone", 499.99, 2);
    itemOrder.print_order();

    return 0;
}
