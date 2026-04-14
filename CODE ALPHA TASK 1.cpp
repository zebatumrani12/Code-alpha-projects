#include <iostream>
#include <iomanip>
using namespace std;

float gradeToPoint(char grade) {
    switch (grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return -1;
    }
}

int main() {
    int courses;
    cout << "Enter number of courses:";
    cin >> courses;

    char grade[courses];
    int credit[courses];

    float totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < courses; i++) {
        cout << "\nCourse " << i + 1 << endl;
        cout << "Enter your  Grade [A/B/C/D/F] ";
        cin >> grade[i];
        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        float gradePoint = gradeToPoint(grade[i]);
        if (gradePoint == -1) {
            cout << "Invalid grade entered!";
            return 0;
        }

        totalGradePoints += gradePoint * credit[i];
        totalCredits += credit[i];
    }

    float GPA = totalGradePoints / totalCredits;

    cout << "\n?? Course Details\n";
    cout << "----------------------------\n";
    cout << "Course\tGrade\tCredits\n";

    for (int i = 0; i < courses; i++) {
        cout << i + 1 << "\t  " << grade[i] << "\t   " << credit[i] << endl;
    }

    cout << "----------------------------\n";
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;

    cout << fixed << setprecision(2);
    cout << "Semester GPA: " << GPA << endl;

    return 0;
}

