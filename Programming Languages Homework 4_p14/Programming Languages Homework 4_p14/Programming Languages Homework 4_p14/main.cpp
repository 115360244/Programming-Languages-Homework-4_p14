#include <iostream>
#include <iomanip>
#include <cstdlib>
#define STUDENTS 5
#define EXAMS 4
using namespace std;

int studentMin(const int setOfGrades[], int tests);
int studentMax(const int setOfGrades[], int tests);
double average(const int setOfGrades[], int tests);
void printArray(const int grades[][EXAMS], int pupils, int tests);

int main()
{
    int student;
    const int studentGrades[STUDENTS][EXAMS] =
    { { 77, 68, 86, 73 },
      { 96, 87, 89, 78 },
      { 70, 90, 86, 81 },
      { 85, 92, 88, 95 },
      { 60, 72, 65, 70 } };

    cout << "The array is:" << endl;
    printArray(studentGrades, STUDENTS, EXAMS);
    cout << "\n\n";

    cout << fixed << setprecision(2);
    for (student = 0; student < STUDENTS; student++)
    {
        cout << "Student " << student
            << " -> Lowest: " << studentMin(studentGrades[student], EXAMS)
            << ", Highest: " << studentMax(studentGrades[student], EXAMS)
            << ", Average: " << average(studentGrades[student], EXAMS) << endl;
    }

    system("pause");
    return 0;
}

int studentMin(const int setOfGrades[], int tests)
{
    int low = setOfGrades[0];
    for (int i = 1; i < tests; i++)
    {
        if (setOfGrades[i] < low)
            low = setOfGrades[i];
    }
    return low;
}

int studentMax(const int setOfGrades[], int tests)
{
    int high = setOfGrades[0];
    for (int i = 1; i < tests; i++)
    {
        if (setOfGrades[i] > high)
            high = setOfGrades[i];
    }
    return high;
}

double average(const int setOfGrades[], int tests)
{
    int total = 0;
    for (int i = 0; i < tests; i++)
    {
        total += setOfGrades[i];
    }
    return static_cast<double>(total) / tests;
}

void printArray(const int grades[][EXAMS], int pupils, int tests)
{
    cout << "                 [0]  [1]  [2]  [3]";
    for (int i = 0; i < pupils; i++)
    {
        cout << "\nstudentGrades[" << i << "] ";
        for (int j = 0; j < tests; j++)
        {
            cout << left << setw(5) << grades[i][j];
        }
    }
}