#include "Student.hpp"
#include <iostream>
using namespace std;
Student::Student() {
    this->id = 0;
    this->name = "";
    this->gpa = 0.0;
    this->courses = nullptr;
    this->numCourses = 0;
    this->maxCourses = 0;
}

Student::Student(int id, string name, float gpa) {
    this->id = id;
    this->name = name;
    this->gpa = gpa;
    this->courses = nullptr;
    this->numCourses = 0;
    this->maxCourses = 0;
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

Course* Student::getCourses() const {
    return courses;
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

void Student::addCourse(Course course) {
    if (courses == nullptr) {
        courses = new Course[1];
        this->maxCourses = 1;
    }

    if (numCourses == maxCourses) {
        Course* newCourses = new Course[maxCourses * 2];
        for (int i = 0; i < numCourses; i++) {
            newCourses[i] = courses[i];
        }
        delete[] courses;
        courses = newCourses;
        maxCourses *= 2;
    }
    courses[numCourses] = course;
    numCourses++;
}

std::ostream& operator<<(std::ostream& os, const Student& obj) {
    os << "ID: " << obj.id << " Name: " << obj.name << " GPA: " << obj.gpa << endl;
    if (obj.courses != nullptr && obj.numCourses > 0) {
        os << "Courses: ";
        for (int i = 0; i < obj.numCourses; i++) {
            os << obj.courses[i] << endl;
        }
    }

    return os;
}