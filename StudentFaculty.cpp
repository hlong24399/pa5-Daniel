#include <iostream>
#include "StudentFaculty.h"
using namespace std;

// class Student {
// public:
//     int studentID;
//     string name;
//     string level;
//     string major;
//     double GPA;
//     int advisorID; // Faculty ID of advisor

//     // Overloaded operators for comparisons
//     bool operator==(const Student& other) const;
//     bool operator<(const Student& other) const;
//     bool operator>(const Student& other) const;
//     // ... other operators as needed
// };

Student::Student() {
    studentID = 0;
    name = "";
    level = "";
    major = "";
    GPA = 0.0;
    advisorID = 0;
}

Student::Student(int id, string n, string l, string m, double g, int a) {
    studentID = id;
    name = n;
    level = l;
    major = m;
    GPA = g;
    advisorID = a;
}

bool Student::operator==(const Student& other) const {
    return studentID == other.studentID;
}

bool Student::operator!=(const Student &other) const
{
    return studentID != other.studentID;
}

bool Student::operator<(const Student& other) const {
    return studentID < other.studentID;
}

bool Student::operator>(const Student& other) const {
    return studentID > other.studentID;
}

ostream &operator<<(ostream &os, const Student &s)
{
    // TODO: insert return statement here
    os << "Student ID: " << s.studentID << endl;
    os << "Name: " << s.name << endl;
    os << "Level: " << s.level << endl;
    os << "Major: " << s.major << endl;
    os << "GPA: " << s.GPA << endl;
    os << "Advisor ID: " << s.advisorID << endl;
    return os;
}
