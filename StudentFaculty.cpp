#include <iostream>
#include "StudentFaculty.h"
using namespace std;

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

int Student::getID() const
{
    return studentID;
}

string Student::getName() const
{
    return name;
}

int Student::getAdvisorID() const
{
    return advisorID;
}

void Student::setAdvisorID(int id)
{
    advisorID = id;
}

bool Student::operator==(const Student& other) const {
    // return studentID == other.studentID;
    return getID() == other.getID();
}

bool Student::operator!=(const Student &other) const
{
    return getID() != other.getID();
}

bool Student::operator<(const Student& other) const {
    return getID() < other.getID();
}

bool Student::operator>(const Student& other) const {
    return getID() > other.getID();
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


Faculty::Faculty() {
    facultyID = 0;
    name = "";
    level = "";
    department = "";
    advisees = {};

}

Faculty::Faculty(int id, string n, string l, string d, vector<int> a) {
    facultyID = id;
    name = n;
    level = l;
    department = d;
    advisees = a;
}

int Faculty::getID() const
{
    return facultyID;
}

string Faculty::getName() const
{
    return name;
}

vector<int> Faculty::getAdvisees() const
{
    return advisees;
}

void Faculty::addAdvisee(int id)
{
    advisees.push_back(id);
}

void Faculty::removeAdvisee(int id)
{
    for (int i = 0; i < advisees.size(); i++)
    {
        if (advisees[i] == id)
        {
            advisees.erase(advisees.begin() + i);
        }
    }
}

bool Faculty::operator==(const Faculty& other) const {
    return getID() == other.getID();
}

bool Faculty::operator!=(const Faculty &other) const
{
    return getID() != other.getID();
}

bool Faculty::operator<(const Faculty& other) const {
    return getID() < other.getID();
}

bool Faculty::operator>(const Faculty& other) const {
    return getID() > other.getID();
}


ostream &operator<<(ostream &os, const Faculty &f)
{
    os << "Faculty ID: " << f.facultyID << endl;
    os << "Name: " << f.name << endl;
    os << "Level: " << f.level << endl;
    os << "Department: " << f.department << endl;
    os << "Advisees: ";
    for (int i = 0; i < f.advisees.size(); ++i) {
        os << f.advisees[i] << " ";
    }
    os << endl;
    return os;
}