#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    double price;

public:
    // Standard Parameterized Constructor
    Book(string t, double p) : title(t), price(p) {
        cout << "Parameterized constructor called for: " << title << "\n";
    }

    // 1. CUSTOM COPY CONSTRUCTOR
    Book(const Book &source) {
        title = source.title + " (Copy)"; // Modifying slightly to track the copy execution
        price = source.price;
        cout << "CUSTOM copy constructor called for: " << title << "\n";
    }

    // Method to display book details
    void display() const {
        cout << "Title: " << title << " | Price: Rs. " << price << "\n";
    }
};

int main() {
    // Creating the original book object
    Book book1("C++ Beginner to Advanced", 750.00);
    cout << "--- book1 details ---\n";
    book1.display();
    cout << "\n";

    // 2. USING THE COPY CONSTRUCTOR
    // This creates book2 as an exact duplicate of book1
    Book book2 = book1; 
    cout << "--- book2 details ---\n";
    book2.display();
    cout << "\n";

    return 0;
}