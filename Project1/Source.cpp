#include <iostream>
using namespace std;
#include "Header.h"
#include "Header1.h"
enum MenuOption 
{
    EXIT = 0,
    ADD_STUDENT,
    REMOVE_STUDENT,
    SHOW_ALL_STUDENTS,
    SORT_BY_NAME,
    SORT_BY_AVERAGE
};
void printMenu() 
{
    cout << "\nSTUDENT MANAGEMENT SYSTEM\n";
    cout << ADD_STUDENT << " - Add new student" << endl;
    cout << REMOVE_STUDENT << " - Remove student by ID" << endl;
    cout << SHOW_ALL_STUDENTS << " - Show all students" << endl;
    cout << SORT_BY_NAME << " - Sort students by name" << endl;
    cout << SORT_BY_AVERAGE << " - Sort students by average score" << endl;
    cout << EXIT << " - Exit" << endl;
    cout << "Select option: ";
}
void runAcademy() 
{
    Student* students = nullptr;
    uint size = 0;
    int choice;

    do 
    {
        printMenu();
        cin >> choice;

        switch (choice) 
        {
        case ADD_STUDENT:
            addStudent(students, size);
            break;
        case REMOVE_STUDENT:
            uint id;
            cout << "Enter ID to remove: ";
            cin >> id;
            removeStudentById(students, size, id);
            break;
        case SHOW_ALL_STUDENTS:
            showAllStudents(students, size);
            break;
        case SORT_BY_NAME:
            sorting(students, size, sortByName);
            break;
        case SORT_BY_AVERAGE:
            sorting(students, size, sortByAverage);
            break;
        case EXIT:
            cout << "Exiting system. Cleaning memory..." << endl;
            break;
        default:
            cout << "Invalid option! Try again." << endl;
            break;
        }
    } while (choice != EXIT);

    if (students != nullptr) 
    {
        clear(students, size);
    }
}
int main()
{
    runAcademy();
    return 0;
}