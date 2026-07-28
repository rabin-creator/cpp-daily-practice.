#include <iostream>
using namespace std;

class B; // forward declaration

class A {
private:
    int dataA;

public:
    A(int val) : dataA(val) {}

    // friend function
    friend void showData(const A& obj);

    // friend class
    friend class B;
};

void showData(const A& obj) {
    cout << "Friend function: " << obj.dataA << endl;
}

class B {
public:
    void display(const A& obj) {
        cout << "Friend class: " << obj.dataA << endl;
    }
};

int main() {
    A objA(42);
    B objB;

    showData(objA);     // friend function
    objB.display(objA); // friend class

    return 0;
}
