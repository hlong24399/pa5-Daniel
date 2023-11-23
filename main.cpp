#include "LBBST.h"  // Assuming you've named your Lazily Balanced BST file as "LBBST.h"
#include "StudentFaculty.h"
#include <iostream>
using namespace std;


int main() {
    // LBBST<int> lbTree;
    // lbTree.insert(4);
    // lbTree.insert(10);
    // lbTree.insert(2);
    // lbTree.insert(3);
    // lbTree.insert(1);
    // lbTree.insert(6);
    // cout << "The size is: " << lbTree.getSize() << endl;
    // cout << "=== Print Tree In Order ===" << endl;
    // lbTree.printTreeInOrder();
    // cout << "=== Print Tree Post Order ====" << endl;
    // lbTree.printTreePostOrder();
    // cout << "=== Testing contains ====" << endl;
    // cout << lbTree.contains(10) << endl;
    // cout << lbTree.contains(5) << endl;
    // cout << "=== Testing extrema ===" << endl;
    // cout << "Max: " << lbTree.getMax() << endl;
    // cout << "Min: " << lbTree.getMin() << endl;
    // cout << "=== Testing remove ===" << endl;
    // lbTree.remove(1);
    // cout << "-- Result of remove --" << endl;
    // lbTree.printTreeInOrder();



    LBBST<Student> lbTree;
    Student s1(1, "John", "Freshman", "Computer Science", 3.5, 2);
    Student s2(2, "Jane", "Senior", "Mathematics", 3.8, 3);
    Student s3(3, "Jack", "Junior", "Computer Science", 3.2, 1);
    Student s4(4, "Jill", "Sophomore", "Computer Science", 3.9, 2);


    lbTree.insert(s1);
    lbTree.insert(s2);
    lbTree.insert(s3);

    cout << "=== Print Tree In Order ===" << endl;
    lbTree.printTreeInOrder();
    cout << "=== Print Tree Post Order ====" << endl;
    lbTree.printTreePostOrder();
    cout << "=== Testing contains ====" << endl;
    cout << lbTree.contains(s1) << endl;
    cout << lbTree.contains(s4) << endl;
    cout << "=== Testing extrema ===" << endl;
    cout << "Max: " << lbTree.getMax() << endl;
    cout << "Min: " << lbTree.getMin() << endl;
    cout << "=== Testing remove ===" << endl;
    lbTree.remove(s1);
    cout << "-- Result of remove --" << endl;
    lbTree.printTreeInOrder();
    


    return 0;
}