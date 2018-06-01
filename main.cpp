#include "vector.h"

int main()
{
    /** Creating vector of int type, in this case we will call the Parameterized Constructor. */
    int array[2] = { 2, 4 };
    Vector<int> myVector(array, 4, 2);

    /** adding elements into vector */
    myVector.Push_back(6);
    myVector.Push_back(3);
    myVector.Push_back(7);
    myVector.Push_back(1);
    myVector.Push_back(5);

    /** inserting element at position */
    myVector.Insert(10, 3);
    myVector.Insert(54, 5);

    /** print the vector */
    cout << "Vector elements: ";
    myVector.Print();
    cout << endl;

    /** Creating new vector with that will be a copy of the one above, in this case we call the Copy Constructor */
    Vector<int> copyVector(myVector);

    /** Print copied vector */
    cout << "Copied vector elements: ";
    copyVector.Print();
    cout << endl;

    /** Creating new vector with assignment operator, almost the same as the Copy Constructor */
    Vector<int> assignmentVector = copyVector;

    /** Print assignment vector */
    cout << "Assignment vector elements: ";
    assignmentVector.Print();
    cout << endl;

    /** first and last element of vector */
    cout << "First element: " << assignmentVector.Front() << "\nLast element: " << assignmentVector.Back() << endl;

    /** remove last element of vector, in this case we remove 5 */
    assignmentVector.Pop_back();
    cout << "New vector elements: ";
    assignmentVector.Print();
    cout << endl;

    /** remove element at position, in this case we remove 3 on fourth position */
    assignmentVector.Erase(4);
    cout << "New vector elements: ";
    assignmentVector.Print();
    cout << endl;

    /** sort vector */
    assignmentVector.Sort();

    /** print sorted vector */
    cout << "Sorted vector elements: ";
    assignmentVector.Print();
    cout << endl;

    /** clear vector */
    assignmentVector.Clear();

    /** print empty vector*/
    cout << "Cleared vector: " << (assignmentVector.IsEmpty() == true ? "yes " : "false ");
    assignmentVector.Print();
    cout << endl;

    return 0;
}
