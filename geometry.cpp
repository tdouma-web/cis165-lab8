#include <iostream>

using namespace std;

int main() {
    // Named constant in ALL_CAPS as required
    const double PI = 3.14159;

    // Variables using meaningful lowercase / camelCase names
    int choice;
    double radius;
    double length;
    double width;
    double base;
    double height;
    double area;

    // Display the Geometry Calculator menu
    cout << "Geometry Calculator\n";
    cout << "1. Calculate the Area of a Circle\n";
    cout << "2. Calculate the Area of a Rectangle\n";
    cout << "3. Calculate the Area of a Triangle\n";
    cout << "4. Quit\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    // Route the user's menu choice and validate inputs
    if (choice == 1) {
        cout << "Enter the circle's radius: ";
        cin >> radius;

        // Reject negative radius before calculating
        if (radius < 0.0) {
            cout << "Error: The radius cannot be negative.\n";
        } else {
            // Calculate first and store in a variable before displaying
            area = PI * radius * radius;
            cout << "Area of the circle: " << area << "\n";
        }
    } else if (choice == 2) {
        cout << "Enter the rectangle's length: ";
        cin >> length;
        cout << "Enter the rectangle's width: ";
        cin >> width;

        // Reject negative length or width before calculating
        if (length < 0.0 || width < 0.0) {
            cout << "Error: Length and width cannot be negative.\n";
        } else {
            area = length * width;
            cout << "Area of the rectangle: " << area << "\n";
        }
    } else if (choice == 3) {
        cout << "Enter the triangle's base: ";
        cin >> base;
        cout << "Enter the triangle's height: ";
        cin >> height;

        // Reject negative base or height before calculating
        if (base < 0.0 || height < 0.0) {
            cout << "Error: Base and height cannot be negative.\n";
        } else {
            // Use 0.5 for floating-point calculation
            area = base * height * 0.5;
            cout << "Area of the triangle: " << area << "\n";
        }
    } else if (choice == 4) {
        // End without asking for dimensions or calculating an area
        cout << "Program ending.\n";
    } else {
        // Error for numeric menu choice outside 1 through 4
        cout << "Error: Invalid choice. Please run the program again and enter a number from 1 to 4.\n";
    }

    return 0;
}