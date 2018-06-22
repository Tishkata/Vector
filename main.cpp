#include "vector.h"

int main()
{
        /** Creating vector of int type, in this case we will call the Parameterized Constructor. */
    int array[2] = { 2, 4 };
    Vector<int> myVector(array, 4, 2);

    /** adding elements into vector */
    myVector.push_back(6);
    myVector.push_back(3);
    myVector.push_back(7);
    myVector.push_back(1);
    myVector.push_back(6);

    /** inserting element at position */
    myVector.insert(10, 3);
    myVector.insert(54, 5);

    /** print the vector */
    cout << "Vector elements: ";
    myVector.print();
    cout << endl;

    /** Creating new vector with that will be a copy of the one above, in this case we call the Copy Constructor */
    Vector<int> copyVector(myVector);

    /** Print copied vector */
    cout << "Copied vector elements: ";
    copyVector.print();
    cout << endl;

    /** Creating new vector with assignment operator, almost the same as the Copy Constructor */
    Vector<int> assignmentVector = copyVector;

    /** Print assignment vector */
    cout << "Assignment vector elements: ";
    assignmentVector.print();
    cout << endl;

    /** first and last element of vector */
    cout << "First element: " << assignmentVector.front() << "\nLast element: " << assignmentVector.back() << endl;

    /** remove last element of vector, in this case we remove 5 */
    assignmentVector.pop_back();
    cout << "New vector elements: ";
    assignmentVector.print();
    cout << endl;

    /** remove element at position, in this case we remove 3 on fourth position */
    assignmentVector.erase(4);
    cout << "New vector elements: ";
    assignmentVector.print();
    cout << endl;

    /** sort vector */
    assignmentVector.sort();

    /** print sorted vector */
    cout << "Sorted vector elements: ";
    assignmentVector.print();
    cout << endl;

    /** clear vector */
    assignmentVector.clear();

    /** print empty vector*/
    cout << "Cleared vector: " << (assignmentVector.empty() == true ? "yes " : "no ") << endl;
    assignmentVector.print();
    cout << endl;

    return 0;
}
