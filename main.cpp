#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Student {
private:
    int id;
    string name;
    float gpa;

public:
    // Constructor
    Student(int i, string n, float g) {
        id = i;
        name = n;
        gpa = g;
    }

    // Default Constructor
    Student() {
        id = 0;
        name = "";
        gpa = 0.0;
    }

    // Setters
    void setData(int i, string n, float g) {
        id = i;
        name = n;
        gpa = g;
    }

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    float getGpa() const { return gpa; }

    // Display
    void display() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "GPA: " << gpa << endl;
        cout << "------------------------" << endl;
    }

    // Save to file
    void saveToFile(ofstream &file) {
        file << id << " " << name << " " << gpa << endl;
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        int id;
        string name;
        float gpa;

        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter GPA: ";
        cin >> gpa;

        Student s(id, name, gpa);
        students.push_back(s);

        cout << "Student Added Successfully!\n";
    }

    void displayStudents() {
        if (students.empty()) {
            cout << "No students available.\n";
            return;
        }

        for (const auto &s : students) {
            s.display();
        }
    }

    void searchStudent() {
        int id;
        cout << "Enter ID to search: ";
        cin >> id;

        for (const auto &s : students) {
            if (s.getId() == id) {
                s.display();
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void saveAllToFile() {
        ofstream file("students.txt");
        for (auto &s : students) {
            s.saveToFile(file);
        }
        file.close();
        cout << "Data saved to file.\n";
    }
};

int main() {
    StudentManager manager;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Save to File\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.addStudent();
            break;
        case 2:
            manager.displayStudents();
            break;
        case 3:
            manager.searchStudent();
            break;
        case 4:
            manager.saveAllToFile();
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
