#include "vector.h"

int main()
{
    /** Creating vector of int type, in this case we will call the Parameterized Constructor. */
    int array[2] = { 2, 4 };
    Vector<int> myVector(array, 2, 4);

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
    std::cout << "Vector elements: ";
    for(Vector<int>::Iterator itr = myVector.begin(); itr != myVector.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    /** Creating new vector with that will be a copy of the one above, in this case we call the Copy Constructor */
    Vector<int> copyVector(myVector);

    /** Print copied vector */
    std::cout << "Copied vector elements: ";
    for(Vector<int>::Iterator itr = copyVector.begin(); itr != copyVector.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    /** Creating new vector with assignment operator, almost the same as the Copy Constructor */
    Vector<int> assignmentVector = copyVector;

    /** Print assignment vector */
    std::cout << "Assignment vector elements: ";
    for(Vector<int>::Iterator itr = assignmentVector.begin(); itr != assignmentVector.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    /** first and last element of vector */
    std::cout << "First element: " << assignmentVector.front() << "\nLast element: " << assignmentVector.back() << std::endl;

    /** remove last element of vector, in this case we remove 5 */
    assignmentVector.pop_back();
    std::cout << "New vector elements: ";
    for(Vector<int>::Iterator itr = assignmentVector.begin(); itr != assignmentVector.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    /** remove element at position, in this case we remove 3 on fourth position */
    assignmentVector.erase(4);
    std::cout << "New vector elements: ";
    for(Vector<int>::Iterator itr = assignmentVector.begin(); itr != assignmentVector.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    /** sort vector */
    assignmentVector.sort();

    /** print sorted vector */
    std::cout << "Sorted vector elements: ";
    for(Vector<int>::Iterator itr = assignmentVector.begin(); itr != assignmentVector.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    /** clear vector */
    assignmentVector.clear();

    /** print empty vector*/
    std::cout << "Cleared vector: " << (assignmentVector.empty() == true ? "yes " : "no ") << std::endl;
    if(assignmentVector.empty() == false)
    {
        for(Vector<int>::Iterator itr = assignmentVector.begin(); itr != assignmentVector.end(); itr++)
        {
            std::cout << *itr << " ";
        }
    }
    else
    {
        std::cout << "Vector elements: None" << std::endl;
    }

    return 0;
}
