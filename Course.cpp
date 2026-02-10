#include "Course.hpp"
#include <string>
#include <iostream>
using namespace std;

Course::Course() {
    courseName = "";
    location = "";
}

Course::Course(string courseName, string location) {
    this->courseName = courseName;
    this->location = location;
}

void Course::setCourse(string newName) {
    this->courseName = newName;
}

void Course::setLocation(string location) {
    this->location = location;
}

string Course::getCourse() const {
    return this->courseName;
}

string Course::getLocation() const {
    return this->location;
}

ostream& operator<<(ostream& os, const Course &obj) {
    os << obj.courseName << " " << obj.location;
    return os;
}
