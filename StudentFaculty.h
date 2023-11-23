#include <string>
#include <vector>
using namespace std;

class Student {
public:
    int studentID;
    string name;
    string level;
    string major;
    double GPA;
    int advisorID; // Faculty ID of advisor

    // Overloaded operators for comparisons
    bool operator==(const Student& other) const;
    bool operator!=(const Student& other) const;
    bool operator<(const Student& other) const;
    bool operator>(const Student& other) const;
    
    // cout operator overload
    friend ostream& operator<<(ostream& os, const Student& s);
    
    Student();
    Student(int id, string n, string l, string m, double g, int a);

};

class Faculty {
public:
    int facultyID;
    string name;
    string level;
    string department;
    vector<int> advisees; // List of student IDs

    // Overloaded operators for comparisons
    bool operator==(const Faculty& other) const;
    bool operator<(const Faculty& other) const;
    bool operator>(const Faculty& other) const;
    // ... other operators as needed
};