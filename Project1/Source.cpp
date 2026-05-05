#include <iostream>
using namespace std;
#include "Header.h"
#include "Header1.h"
int main()
{
	uint size;
	cout << "Enter size: ";
	cin >> size;

	//cin.ignore();
	Student* students = new Student[size];
	for (uint i = 0; i < size; i++)
	{
		students[i] = createStudent();
	}
	for (uint i = 0; i < size; i++)
	{
		showStudent(students[i]);
	}
    addStudent(students, size);
    cout << endl;
    cout << "List after adding" << endl;
    for (uint i = 0; i < size; i++)
    {
        showStudent(students[i]);
    }
    uint idToDelete;
    cout << "Enter ID to delete: " << endl;
    cin >> idToDelete;
    removeStudentById(students, size, idToDelete);
    cout << endl;
    cout << "Final list" << endl;
    for (uint i = 0; i < size; i++)
    {
        showStudent(students[i]);
    }
    clear(students, size);
    return 0;
}