#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "Course.hpp"
using namespace std;

class Student {
    private:
        int id;
        string name;
        float gpa;
        Course* courses;    // will be dynmically allocated
        int numCourses;    // number of courses the student is taking
        int maxCourses;    // memory allocated for courses array
    
    public:
        Student();
        Student(int id, string name, float gpa);

        int getId() const;
        string getName() const;
        float getGpa() const;
        Course* getCourses() const;
        
        void setId(int id);
        void setName(string name);
        void setGpa(float gpa);
        void addCourse(Course course);

        friend std::ostream& operator<<(std::ostream& os, const Student& obj);
        
};

#endif