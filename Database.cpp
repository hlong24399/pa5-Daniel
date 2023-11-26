#include "Database.h"
#include <iostream>
#include <fstream>
using namespace std;



void DatabaseSystem::printAllStudents() {
    studentTable.printTreeInOrder();
}

void DatabaseSystem::printAllFaculty() {
    facultyTable.printTreeInOrder();
}

void DatabaseSystem::findAndDisplayStudent(int studentID) {
    Student s = studentTable.get(studentID);

    if (s.getName() == "") {
        cout << "Student not found" << endl;
        return;
    }

    cout << s << endl;
}

void DatabaseSystem::findAndDisplayFaculty(int facultyID) {
    Faculty f = facultyTable.get(facultyID);

    if (f.getName() == "") {
        cout << "Faculty not found" << endl;
        return;
    }

    cout << f << endl;
}

void DatabaseSystem::addNewStudent(const Student& student) {
    
    // check if advisor ID is valid

    
    if (isValidAdvisor(student.getAdvisorID()))
    {
        studentTable.insert(student);
        // update faculty adviseeID to add this new student id
        Faculty f = facultyTable.get(student.getAdvisorID());
        facultyTable.remove(f);
        f.addAdvisee(student.getID());
        facultyTable.insert(f);
    }
    else
    {
        cout << "Advisor ID is not valid, please try again" << endl;
    }    
}

void DatabaseSystem::deleteStudent(int studentID) {
    Student s = studentTable.get(studentID);
    cout << "deleting student" << s << endl;
    studentTable.remove(s);
}

void DatabaseSystem::addNewFaculty(const Faculty& faculty) {
    
    // check if advisee ID is valid
    for (int i = 0; i < faculty.getAdvisees().size(); i++)
    {
        if (!isValidAdvisee(faculty.getAdvisees()[i]))
        {
            cout << "Advisee ID is not valid, please try again" << endl;
            return;
        }
    }
    
    // check if the advisee has the right advisor ID
    for (int i = 0; i < faculty.getAdvisees().size(); i++)
    {
        if (studentTable.get(faculty.getAdvisees()[i]).getAdvisorID() != faculty.getID())
        {
            cout << "Advisee cannbe be added to this faculty since students are having different advisors, try again with empty advisee, and use option 9 to update student advisor" << endl;
            return;
        }
    }
    facultyTable.insert(faculty);
}

void DatabaseSystem::deleteFaculty(int facultyID) {
    Faculty f = facultyTable.get(facultyID);
    cout << "deleting faculty" << f.getAdvisees().size() << endl;
    // when removing faculty, need to remove faculty ID from all advisees
    removeAdvisorIdFromAdvisees(facultyID);

    facultyTable.remove(f);
}

void DatabaseSystem::changeAdvisor(int studentID, int facultyID) {
    
    // remove student ID from old faculty advisee list
    Student s = studentTable.get(studentID);
    studentTable.remove(s);

    // update student advisor ID to faculty ID
    s.setAdvisorID(facultyID);
    studentTable.insert(s);

}

void DatabaseSystem::removeAdvisee(int facultyID, int studentID) 
{
    // remove the student ID from the faculty advisee list
    Faculty f = facultyTable.get(facultyID);
    facultyTable.remove(f);
    f.removeAdvisee(studentID);
    facultyTable.insert(f);

    // update student advisor ID to -1
    Student s = studentTable.get(studentID);
    studentTable.remove(s);
    
    // let user enter new faculty id
    int newFacultyID;
    cout << "Enter new faculty ID for student " << s.getName() << ": ";
    cin >> newFacultyID;

    // update student advisor ID to faculty ID
    s.setAdvisorID(newFacultyID);
    studentTable.insert(s);
}

void DatabaseSystem::addAdvisee(int facultyID, int studentID)
{
    // add the student ID to the faculty advisee list
    Faculty f = facultyTable.get(facultyID);
    facultyTable.remove(f);
    f.addAdvisee(studentID);
    facultyTable.insert(f);

    // update student advisor ID to faculty ID
    Student s = studentTable.get(studentID);
    studentTable.remove(s);
    s.setAdvisorID(facultyID);
    studentTable.insert(s);
}

void DatabaseSystem::exit() {
    ofstream runLog;
    runLog.open("runlog.txt");
    // call writeTreetoFile
    studentTable.writeTreetoFile(runLog);
    facultyTable.writeTreetoFile(runLog);

}

bool DatabaseSystem::isValidAdvisor(int facultyID)
{
    // check to makre sure that the faculty ID is valid
    if (facultyTable.get(facultyID).getName() == "")
    {
        return false;
    }
    return true;
    
}

bool DatabaseSystem::isValidAdvisee(int studentID)
{
    // check to make sure all advisees are valid student id that exists in the student table
    if (studentTable.get(studentID).getName() == "")
    {
        return false;
    }
    return true;
}

void DatabaseSystem::removeAdvisorIdFromAdvisees(int facultyID)
{
    // remove faculty ID from all advisees
    Faculty f = facultyTable.get(facultyID);
    cout << f.getAdvisees().size() << endl;
    for (int i = 0; i < f.getAdvisees().size(); i++)
    {   
        
        
        Student s = studentTable.get(f.getAdvisees()[i]);
        
        // let student enters new advisor ID
        int newAdvisorID;
        cout << "Enter new advisor ID for student " << s.getName() << ": ";
        cin >> newAdvisorID;


        s.setAdvisorID(newAdvisorID);
    }
}
