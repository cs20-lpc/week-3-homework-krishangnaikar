#include "Student.hpp"
#include "Course.hpp"
#include <iostream>
using namespace std;
Student::Student() {
    this->id = 0;
    this->name = "";
    this->gpa = 0.0;
    this->courses;
}

Student::Student(int id, string name, float gpa) {
    this->id = id;
    this->name = name;
    this->gpa = gpa;
    this->courses;
}

int Student::getId() const {
    return id;
}

string Student::getName() const {
    return name;
}

float Student::getGpa() const {
    return gpa;
}


void Student::setId(int id) {
    this->id = id;
}

void Student::setName(string name) {
    this->name = name;
}

void Student::setGpa(float gpa) {
    this->gpa = gpa;
}
LinkedList<Course> Student::getCourses() const {
    return courses;
}

void Student::addCourse(const Course& course) {
    courses.append(course);
}

void Student::printCourses() const {
    for (int i = 0; i < courses.getLength(); i++) {
        cout << courses.get(i) << endl;
    }
}


std::ostream& operator<<(std::ostream& os, const Student& obj) {
    os << "ID: " << obj.id << " Name: " << obj.name << " GPA: " << obj.gpa << endl;
    if (obj.getCourses().getLength() > 0) {
        os << "Courses:\n";
        obj.printCourses();
    }
    return os;
}
