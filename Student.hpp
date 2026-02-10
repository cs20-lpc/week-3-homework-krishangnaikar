#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include "Course.hpp"
#include "LinkedList.hpp"
using namespace std;

class Student {
    private:
        int id;
        string name;
        float gpa;
        LinkedList<Course> courses;
    
    public:
        Student();
        Student(int id, string name, float gpa);

        int getId() const;
        string getName() const;
        float getGpa() const;
        LinkedList<Course> getCourses() const;
        void setId(int id);
        void setName(string name);
        void setGpa(float gpa);
        
        void addCourse(const Course& course);
        void printCourses() const;


        friend std::ostream& operator<<(std::ostream& os, const Student& obj);
        
};

#endif