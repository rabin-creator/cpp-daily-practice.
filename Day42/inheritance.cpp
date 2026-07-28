#include <iostream>
#include <string>

// Parent Class (Base Class)
class Animal {
public:
    std::string name;

    Animal(std::string animalName)
     {
        name = animalName;
    }

    void eat()
     {
        std::cout << name << " is eating." << std::endl;
    }
};

// Child Class (Derived Class) inheriting from Animal
class Dog : public Animal {
public:
    // Constructor passes the name up to the Parent constructor
    Dog(std::string dogName) : Animal(dogName) {}

    void bark() {
        std::cout << name << " says Woof!" << std::endl;
    }
};

int main() {
    // 1. Create an object of the child class
    Dog myDog("Buddy");

    // 2. Call a method inherited from the parent class
    myDog.eat();  // Output: Buddy is eating.

    // 3. Call a method unique to the child class
    myDog.bark(); // Output: Buddy says Woof!

    return 0;
}