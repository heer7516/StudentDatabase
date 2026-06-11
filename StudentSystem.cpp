// StudentSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "StudentSystem.h"

int main()
{
    srand((unsigned)time(0));

    Student students[MAX_STUDENTS];

    double grades[MAX_STUDENTS][NUM_ASSIGNMENTS];

    int count = 0;

    loadStudents(students, count);

    cout << "Students Loaded = " << count << endl;

    generateGrades(grades, count);

    calculateAverages(grades, students, count);

    int choice;

    do
    {
        cout << "\n====== STUDENT SYSTEM ======\n";
        cout << "1. Display All Students Info\n";
        cout << "2. Update Assignment\n";
        cout << "3. Add Student\n";
        cout << "4. Save To File\n";
        cout << "5. Highlight Student / Assignment\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayAllStudentInfo(grades, students, count);
            break;

        case 2:
            updateAssignment(grades, students, count);
            break;

        case 3:
            addStudent(students, count, grades);
            break;

        case 4:
            saveStudents(students, count);
            break;

        case 5:
            highlightSearch(grades, students, count);
            break;

        case 6:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
