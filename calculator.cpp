#include <iostream>
using namespace std;

int main() {
    int a, b, choice;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\n1. Addition";
    cout << "\n2. Subtraction";
    cout << "\n3. Multiplication";
    cout << "\n4. Division";
    cout << "\n5. Modulus";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Addition = " << a + b;
            break;

        case 2:
            cout << "Subtraction = " << a - b;
            break;

        case 3:
            cout << "Multiplication = " << a * b;
            break;

        case 4:
            if(b != 0)
                cout << "Division = " << (float)a / b;
            else
                cout << "Division by zero is not possible.";
            break;

        case 5:
            if(b != 0)
                cout << "Modulus = " << a % b;
            else
                cout << "Modulus by zero is not possible.";
            break;

        default:
            cout << "Invalid Choice";
    }

    return 0;
}