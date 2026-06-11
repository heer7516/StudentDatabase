#ifndef STUDENTSYSTEM_H
#define STUDENTSYSTEM_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//================ STRUCT =================

struct Student
{
    string firstName;
    string lastName;
    int id;
    double grade;
};

//================ CONSTANTS =================

const int MAX_STUDENTS = 23;
const int NUM_ASSIGNMENTS = 5;

//================ FUNCTION PROTOTYPES =================

void loadStudents(Student students[], int& count);

void generateGrades(double grades[][NUM_ASSIGNMENTS], int count);

void calculateAverages(double grades[][NUM_ASSIGNMENTS],
    Student students[],
    int count);

void displayAllStudentInfo(double grades[][NUM_ASSIGNMENTS],
    Student students[],
    int count);

void updateAssignment(double grades[][NUM_ASSIGNMENTS],
    Student students[],
    int count);

void addStudent(Student students[],
    int& count,
    double grades[][NUM_ASSIGNMENTS]);

void saveStudents(Student students[],
    int count);

void highlightSearch(double grades[][NUM_ASSIGNMENTS],
    Student students[],
    int count);

#endif