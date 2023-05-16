#include <iostream>
#include <string>
using namespace std;

class Tree {
public:
    virtual void draw() const {
        cout << "This is a base tree." << endl;
    }
};

class PineTree : public Tree {
public:
    void draw() const override {
        cout << "Drawing a pine tree:" << endl;
        cout << "  /\\  " << endl;
        cout << " //\\\\ " << endl;
    }
};

class ChristmasTree : public Tree {
public:
    void draw() const override {
        cout << "Drawing a Christmas tree:" << endl;
        cout << "  /\\  " << endl;
        cout << " /**\\ " << endl;
    }
};

class PalmTree : public Tree {
public:
    void draw() const override {
        cout << "Drawing a palm tree:" << endl;
        cout << "  /\\  " << endl;
        cout << " /++\\ " << endl;
    }
};

int main() {
    Tree* treeArray[3];
    treeArray[0] = new PineTree();
    treeArray[1] = new ChristmasTree();
    treeArray[2] = new PalmTree();

    for (int i = 0; i < 3; i++) {
        cout << "Drawing " << i + 1 << ":" << endl;
        treeArray[i]->draw();
        cout << endl;
    }

    // Clean up allocated memory
    for (int i = 0; i < 3; i++) {
        delete treeArray[i];
    }

    return 0;
}
