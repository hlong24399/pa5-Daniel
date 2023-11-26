#include "LBBST.h" // Assuming you've named your Lazily Balanced BST file as "LBBST.h"
#include "StudentFaculty.h"
#include "Database.h"
#include <iostream>
using namespace std;

int main()
{
    /*
Once the tables have been created, a menu should be presented to the user to allow them to
manipulate the database. The choices should include:
1. Print all students and their information (sorted by ascending id #)
2. Print all faculty and their information (sorted by ascending id #)
3. Find and display student information given the student id
4. Find and display faculty information given the faculty id
5. Add a new student
6. Delete a student given the id
7. Add a new faculty member
8. Delete a faculty member given the id.
9. Change a student’s advisor given the student id and the new faculty id.
10. Remove an advisee from a faculty member given the ids
    */

        // create a DatabaseSystem object
        DatabaseSystem db;


        // add some students and faculty for testing
        Faculty f1(1, "John", "Professor", "Mathematics", {});
        Faculty f2(2, "Jane", "Professor", "History", {});
        Faculty f3(5, "Jack", "Professor", "Dance", {});
        
        
        Student s1(1, "John", "Freshman", "Mathematics", 3.5, 1);
        Student s2(2, "Jane", "Sophomore", "History", 3.2, 2);
        Student s3(3, "Jack", "Junior", "Dance", 3.8, 5);
        Student s4(4, "Jill", "Senior", "Biology", 3.9, 2);
        Student s5(5, "Hank", "Senior", "English", 3.9, 1);

        // add faculty first
        db.addNewFaculty(f1);
        db.addNewFaculty(f2);
        db.addNewFaculty(f3);
        

        // add students will automatically update faculty advisee list
        db.addNewStudent(s1);
        db.addNewStudent(s2);
        db.addNewStudent(s3);
        db.addNewStudent(s4);
        db.addNewStudent(s5);

    int choice = 0;

    while (choice != 11)
    {
        // print menu
        cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
        cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
        cout << "3. Find and display student information given the student id" << endl;
        cout << "4. Find and display faculty information given the faculty id" << endl;
        cout << "5. Add a new student" << endl;
        cout << "6. Delete a student given the id" << endl;
        cout << "7. Add a new faculty member" << endl;
        cout << "8. Delete a faculty member given the id." << endl;
        cout << "9. Change a student's advisor given the student id and the new faculty id." << endl;
        cout << "10. Remove an advisee from a faculty member given the ids" << endl;
        cout << "11. Exit" << endl;

        cin >> choice;

        if (choice == 1)
        {
            // print all students
            db.printAllStudents();
        }
        else if (choice == 2)
        {
            // print all faculty
            db.printAllFaculty();
        }
        else if (choice == 3)
        {
            // find and display student info
            int studentID;
            cout << "Enter student ID: ";
            cin >> studentID;
            db.findAndDisplayStudent(studentID);
        }
        else if (choice == 4)
        {
            // find and display faculty info
            int facultyID;
            cout << "Enter faculty ID: ";
            cin >> facultyID;
            db.findAndDisplayFaculty(facultyID);
        }
        else if (choice == 5)
        {
            // add a new student
            int id;
            string name;
            string level;
            string major;
            double gpa;
            int advisorID;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter level: ";
            cin >> level;
            cout << "Enter major: ";
            cin >> major;
            cout << "Enter GPA: ";
            cin >> gpa;
            cout << "Enter advisor ID: ";
            cin >> advisorID;
            Student s(id, name, level, major, gpa, advisorID);
            db.addNewStudent(s);
        }
        else if (choice == 6)
        {
            // delete a student
            int studentID;
            cout << "Enter student ID: ";
            cin >> studentID;
            Student s = db.studentTable.get(studentID);
            db.studentTable.remove(s);
        }
        else if (choice == 7)
        {
            // add a new faculty
            int id;
            string name;
            string level;
            string department;
            vector<int> advisees;
            cout << "Enter faculty ID: ";
            cin >> id;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter level: ";
            cin >> level;
            cout << "Enter department: ";
            cin >> department;
            cout << "Enter advisee IDs (enter -1 to stop): ";
            int adviseeID;
            cin >> adviseeID;
            while (adviseeID != -1)
            {
                advisees.push_back(adviseeID);
                cin >> adviseeID;
            }
            Faculty f(id, name, level, department, advisees);
            db.addNewFaculty(f);
        }
        else if (choice == 8)
        {
            // delete a faculty
            int facultyID;
            cout << "Enter faculty ID: ";
            cin >> facultyID;
            db.deleteFaculty(facultyID);
        }
        else if (choice == 9)
        {
            // change a student's advisor
            int studentID;
            int facultyID;
            cout << "Enter student ID: ";
            cin >> studentID;
            cout << "Enter faculty ID: ";
            cin >> facultyID;
            db.changeAdvisor(studentID, facultyID);
        }
        else if (choice == 10)
        {
            // remove an advisee from a faculty
            int facultyID;
            int studentID;
            cout << "Enter faculty ID: ";
            cin >> facultyID;
            cout << "Enter student ID: ";
            cin >> studentID;
            db.removeAdvisee(facultyID, studentID);
        }
        else if (choice == 11)
        {
            // exit
            db.exit();
        }
        else
        {
            cout << "Invalid choice, please try again" << endl;
        }
    }
    return 0;


}