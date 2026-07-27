#include <iostream>

// ==========================================
// 1. Preventing Class Inheritance
// ==========================================
class BaseClass final {
public:
    void show() {
        std::cout << "Inside BaseClass\n";
    }
};

// ERROR: Cannot inherit from a 'final' class
// class DerivedClass : public BaseClass {}; 


// ==========================================
// 2. Preventing Virtual Method Overriding
// ==========================================
class Parent {
public:
    virtual void processData() {
        std::cout << "Parent: Processing default data...\n";
    }

    virtual void logStatus() final { // Cannot be overridden by derived classes
        std::cout << "Parent: Logging status...\n";
    }
};

class Child : public Parent {
public:
    // ALLOWED: processData() is virtual and not final in Parent
    void processData() override {
        std::cout << "Child: Processing customized data...\n";
    }

    // ERROR: Overriding a final function leads to a compile error
    /*
    void logStatus() override { 
        std::cout << "Child: Trying to change logging...\n";
    }
    */
};

int main() {
    Child childObj;
    childObj.processData();
    childObj.logStatus(); // Inherited normally, just can't be overridden

    return 0;
}