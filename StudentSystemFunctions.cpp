#include "StudentSystem.h"
void loadStudents(Student students[], int& count)
{
    ifstream fin("students.txt");

   
    count = 0;

    while (fin >> students[count].firstName
        >> students[count].lastName
        >> students[count].id
        >> students[count].grade)
    {
        count++;

        if (count >= MAX_STUDENTS)
        {
            break;
        }
    }

    fin.close();
}

void generateGrades(double grades[][NUM_ASSIGNMENTS], int count)
{
    for (int row = 0; row < count; row++)
    {
        for (int col = 0; col < NUM_ASSIGNMENTS; col++)
        {
            grades[row][col] = rand() % 41 + 60;
        }
    }
}

void calculateAverages(double grades[][NUM_ASSIGNMENTS],
    Student students[],
    int count)
{
    for (int row = 0; row < count; row++)
    {
        double total = 0;

        for (int col = 0; col < NUM_ASSIGNMENTS; col++)
        {
            total += grades[row][col];
        }

        students[row].grade = total / NUM_ASSIGNMENTS;
    }
}
void displayAllStudentInfo(double grades[][NUM_ASSIGNMENTS],
    Student students[],
    int count)
{
    cout << "\n========== ALL STUDENT RECORDS ==========\n";

    cout << left
        << setw(8) << "ID"
        << setw(12) << "FName"
        << setw(12) << "LName"
        << setw(6) << "A1"
        << setw(6) << "A2"
        << setw(6) << "A3"
        << setw(6) << "A4"
        << setw(6) << "A5"
        << setw(8) << "AVG"
        << endl;

    for (int row = 0; row < count; row++)
    {
        cout << left
            << setw(8) << students[row].id
            << setw(12) << students[row].firstName
            << setw(12) << students[row].lastName;

        for (int col = 0; col < NUM_ASSIGNMENTS; col++)
        {
            cout << setw(6) << grades[row][col];
        }

        cout << fixed << setprecision(1)
            << setw(8) << students[row].grade;

        cout << endl;
    }
}
void updateAssignment(double grades[][NUM_ASSIGNMENTS],
    Student students[],
    int count)
{
    int studentID;
    int assignment;
    double newGrade;

    cout << "Enter student ID: ";
    cin >> studentID;

    cout << "Enter assignment number (1-5): ";
    cin >> assignment;

    cout << "Enter new grade: ";
    cin >> newGrade;

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == studentID)
        {
            grades[i][assignment - 1] = newGrade;

            double total = 0;

            for (int j = 0; j < NUM_ASSIGNMENTS; j++)
            {
                total += grades[i][j];
            }

            students[i].grade = total / NUM_ASSIGNMENTS;

            cout << "Assignment updated.\n";

            displayAllStudentInfo(grades, students, count);
            return;
        }
    }

    cout << "Student not found.\n";
}
void addStudent(Student students[],
    int& count,
    double grades[][NUM_ASSIGNMENTS])
{
    if (count >= MAX_STUDENTS)
    {
        cout << "Maximum students reached.\n";
        return;
    }

    cout << "First Name: ";
    cin >> students[count].firstName;

    cout << "Last Name: ";
    cin >> students[count].lastName;

    cout << "ID: ";
    cin >> students[count].id;

    for (int col = 0; col < NUM_ASSIGNMENTS; col++)
    {
        grades[count][col] = rand() % 41 + 60;
    }

    double total = 0;

    for (int col = 0; col < NUM_ASSIGNMENTS; col++)
    {
        total += grades[count][col];
    }

    students[count].grade = total / NUM_ASSIGNMENTS;

    count++;

    cout << "Student added.\n";
}

void saveStudents(Student students[], int count)
{
    ofstream fout("students.txt");

    for (int i = 0; i < count; i++)
    {
        fout << students[i].firstName << " "
            << students[i].lastName << " "
            << students[i].id << " "
            << students[i].grade << endl;
    }

    fout.close();

    cout << "Data saved.\n";
}

void highlightSearch(double grades[][NUM_ASSIGNMENTS],
    Student students[],
    int count)
{
    int choice;

    cout << "\n1. Highlight Student (Row)\n";
    cout << "2. Highlight Assignment (Column)\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == 1)
    {
        int id;

        cout << "Enter student ID: ";
        cin >> id;

        for (int row = 0; row < count; row++)
        {
            if (students[row].id == id)
            {
                cout << "\033[1;32m";
            }

            cout << students[row].id << " "
                << students[row].firstName << " "
                << students[row].lastName << " ";

            for (int col = 0; col < NUM_ASSIGNMENTS; col++)
            {
                cout << grades[row][col] << " ";
            }

            cout << students[row].grade;

            cout << "\033[0m";
            cout << endl;
        }
    }
    else if (choice == 2)
    {
        int assignment;

        cout << "Enter assignment number (1-5): ";
        cin >> assignment;

        for (int row = 0; row < count; row++)
        {
            cout << students[row].id << " ";

            for (int col = 0; col < NUM_ASSIGNMENTS; col++)
            {
                if (col == assignment - 1)
                {
                    cout << "\033[1;31m";
                }

                cout << grades[row][col] << " ";
                cout << "\033[0m";
            }

            cout << endl;
        }
    }
}