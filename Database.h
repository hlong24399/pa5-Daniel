#ifndef DATABASE_H
#define DATABASE_H


#include "StudentFaculty.h"
#include "LBBST.h"

class DatabaseSystem {
public:
    LBBST<Student> studentTable;
    LBBST<Faculty> facultyTable;

public:
    void printAllStudents();
    void printAllFaculty();
    void findAndDisplayStudent(int studentID);
    void findAndDisplayFaculty(int facultyID);
    void addNewStudent(const Student& student);
    
    void deleteStudent(int studentID);
    void addNewFaculty(const Faculty& faculty);
    void deleteFaculty(int facultyID);
    void changeAdvisor(int studentID, int facultyID);
    void removeAdvisee(int facultyID, int studentID);
    void addAdvisee(int facultyID, int studentID);
    void exit();

    // referential integrity
    bool isValidAdvisor(int facultyID);
    bool isValidAdvisee(int studentID);
    void removeAdvisorIdFromAdvisees(int facultyID);
    

};

#endif