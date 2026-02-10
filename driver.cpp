#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"

using namespace std;

int main()
{
    LinkedList<Student> studentList;
    int choice;
    bool running = true;

    while (running) {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Insert Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All\n";
        cout << "5. Count Students\n";
        cout << "6. Add a Course\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                int id;
                string name;
                float gpa;

                cout << "Enter ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter GPA: ";
                cin >> gpa;
                cin.ignore();

                Student newStudent(id, name, gpa);
                studentList.append(newStudent);
                cout << "Student inserted.\n";
                break;
            }

            case 2: {
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;
                cin.ignore();

                int result = studentList.remove(id);
                if (result != -1) {
                    cout << "Deleted student with ID " << id << "\n";
                } else {
                    cout << "Student with ID " << id << " not found.\n";
                }
                break;
            }

            case 3: {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                cin.ignore();

                studentList.search(id);
                break;
            }

            case 4: {
                cout << "\nStudents in List:\n";
                studentList.display();
                break;
            }

            case 5: {
                cout << "Total students: " << studentList.getLength() << "\n";
                break;
            }

            case 6: {
                int id;
                string courseName, location;

                cout << "Enter Student ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Course Name: ";
                getline(cin, courseName);
                cout << "Enter Location: ";
                getline(cin, location);

                Course newCourse(courseName, location);
                bool found = false;
                for (int i = 0; i < studentList.getLength(); i++) {
                    if (studentList.getRef(i).getId() == id) {
                        studentList.getRef(i).addCourse(newCourse);
                        cout << "Course added.\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Student not found.\n";


                break;
            }

            case 7: {
                cout << "Exiting...\n";
                running = false;
                break;
            }

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
