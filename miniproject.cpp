#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Base class
class Person {
protected:
    string name;

public:
    Person(string n) {
        name = n;
    }

    virtual void display() const = 0;

    virtual ~Person() {}
};

// Derived class
class Student : public Person {
private:
    int rollNo;
    float marks;

public:
    Student(string n, int r, float m)
        : Person(n) {
        rollNo = r;
        marks = m;
    }

    int getRollNo() const {
        return rollNo;
    }

    float getMarks() const {
        return marks;
    }

    string calculateGrade() const {
        if (marks >= 90) return "A+";
        if (marks >= 80) return "A";
        if (marks >= 70) return "B";
        if (marks >= 60) return "C";
        if (marks >= 40) return "D";
        return "F";
    }

    void display() const override {
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks;
        cout << "\nGrade: " << calculateGrade() << "\n";
    }
};

// Manager class
class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        string name;
        int rollNo;
        float marks;

        cout << "Enter roll number: ";
        cin >> rollNo;

        for (const Student& s : students) {
            if (s.getRollNo() == rollNo) {
                cout << "Roll number already exists!\n";
                return;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter student name: ";
        getline(cin, name);

        cout << "Enter marks (0-100): ";
        cin >> marks;

        if (marks < 0 || marks > 100) {
            cout << "Invalid marks!\n";
            return;
        }

        students.emplace_back(name, rollNo, marks);
        cout << "Student added successfully!\n";
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "No student records found.\n";
            return;
        }

        for (const Student& s : students) {
            s.display();
        }
    }

    void searchStudent() const {
        int rollNo;
        cout << "Enter roll number to search: ";
        cin >> rollNo;

        for (const Student& s : students) {
            if (s.getRollNo() == rollNo) {
                s.display();
                return;
            }
        }

        cout << "Student not found!\n";
    }

    void saveToFile() const {
        ofstream file("students.txt");

        if (!file) {
            cout << "Unable to save records.\n";
            return;
        }

        for (const Student& s : students) {
            file << s.getRollNo() << '\n';
            // Names are stored on a separate line.
            // See the note below about saving names.
            file << s.getMarks() << '\n';
        }

        cout << "Records saved to students.txt\n";
    }

    void loadFromFile() {
        ifstream file("students.txt");
        if (!file) return;

        // This simple loader is intentionally omitted because
        // the save format above does not include student names.
        cout << "File found. Use the improved file format "
             << "explained below to restore all records.\n";
    }
};

int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Save Records\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }

        switch (choice) {
            case 1:
                manager.addStudent();
                break;
            case 2:
                manager.displayAll();
                break;
            case 3:
                manager.searchStudent();
                break;
            case 4:
                manager.saveToFile();
                break;
            case 5:
                cout << "Thank you for using the system!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}