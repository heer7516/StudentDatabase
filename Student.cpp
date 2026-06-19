#include <iostream>
#include <fstream>
#include <iomanip>
#include "Student.h"

using namespace std;

void loadStudents(StudentNode*& head)
{
    ifstream file("Students90.txt");

    if (!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Student tempStudent;

    while (file >> tempStudent.firstName
        >> tempStudent.lastName
        >> tempStudent.id)
    {
        for (int j = 0; j < NUM_ASSIGNMENTS; j++)
            file >> tempStudent.assignments[j];

        file >> tempStudent.average;

        for (int j = 0; j < NUM_COURSES; j++)
            file >> tempStudent.courses[j];

        StudentNode* newNode = new StudentNode();

        newNode->data = tempStudent;
        newNode->next = head;
        head = newNode;
    }

    file.close();
}
// ================= DISPLAY =================
void displayStudents(StudentNode* head)
{
    StudentNode* current = head;

    while (current != nullptr)
    {
        cout << current->data.id << " "
            << current->data.firstName << " "
            << current->data.lastName << endl;

        current = current->next;
    }
}

void calculateAverage(Student* s)
{
    double total = 0;

    for (int i = 0; i < NUM_ASSIGNMENTS; i++)
    {
        total += s->assignments[i];
    }

    s->average = total / NUM_ASSIGNMENTS;
}

void calculateAllAverages(StudentNode* head)
{
    StudentNode* current = head;

    while (current != nullptr)
    {
        calculateAverage(&current->data);

        current = current->next;
    }
}

  