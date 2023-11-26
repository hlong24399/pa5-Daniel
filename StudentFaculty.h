#ifndef STUDENTFACULTY_H
#define STUDENTFACULTY_H

#include <string>
#include <vector>
using namespace std;

class Student {
private:
    int studentID;
    string name;
    string level;
    string major;
    double GPA;
    int advisorID; // Faculty ID of advisor00

public:
    // Overloaded operators for comparisons
    bool operator==(const Student& other) const;
    bool operator!=(const Student& other) const;
    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;
    
    // cout operator overload
    friend ostream& operator<<(ostream& os, const Student& s);
    Student();
    Student(int id, string n, string l, string m, double g, int a);

    // getter
    int getID() const;
    string getName() const;
    int getAdvisorID() const;

    // setter
    void setAdvisorID(int id);
};

class Faculty {
private:
    int facultyID;
    string name;
    string level;
    string department;
    vector<int> advisees; // List of student IDs

public:
    // Overloaded operators for comparisons
    bool operator==(const Faculty& other) const;
    bool operator!=(const Faculty& other) const;
    bool operator<(const Faculty& other) const;
    bool operator>(const Faculty& other) const;
    
    // cout operator overload
    friend ostream& operator<<(ostream& os, const Faculty& f);
    Faculty();
    Faculty(int id, string n, string l, string d, vector<int> a);

    // getter
    int getID() const;
    string getName() const;
    vector<int> getAdvisees() const;

    // setter
    void addAdvisee(int id);
    void removeAdvisee(int id);
};

#endif