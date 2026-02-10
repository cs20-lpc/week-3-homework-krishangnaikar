#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
using namespace std;


class Course {
    private:
        string courseName;
        string location;

    public:
        Course();
        Course(string courseName, string location);
        void setCourse(string newName);
        void setLocation(string location);
        string getCourse() const;
        string getLocation() const;
        int getId() const;  // dummy function to satisfy LinkedList requirements

        friend std::ostream& operator<<(std::ostream& os, const Course& obj);

};
#endif