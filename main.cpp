#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string department;

    Student(int i, string n, int a, string d) {
        id = i;
        name = n;
        age = a;
        department = d;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Department: " << department << endl;
        cout << "-------------------" << endl;
    }
};

vector<Student> students;

void addStudent() {
    int id, age;
    string name, dept;
    cout << "Enter ID: "; cin >> id;
    cin.ignore();
    cout << "Enter Name: "; getline(cin, name);
    cout << "Enter Age: "; cin >> age;
    cin.ignore();
    cout << "Enter Department: "; getline(cin, dept);

    students.push_back(Student(id, name, age, dept));
    cout << "Student added successfully!\n";
}

void viewStudents() {
    if(students.empty()) {
        cout << "No students found.\n";
        return;
    }
    for(auto s : students) s.display();
}

void searchStudent() {
    int id;
    cout << "Enter ID to search: "; cin >> id;
    for(auto s : students) {
        if(s.id == id) {
            s.display();
            return;
        }
    }
    cout << "Student not found.\n";
}

void menu() {
    int choice;
    do {
        cout << "\n--- Student Management Menu ---\n";
        cout << "1. Add Student\n2. View All Students\n3. Search Student\n4. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 4);
}

int main() {
    menu();
    return 0;
}

