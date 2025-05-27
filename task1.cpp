#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int numCourses;
    float credit, gradePoint;
    float totalCredits = 0.0, totalGradePoints = 0.0;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 1; i <= numCourses; i++) {
        cout << "\nCourse " << i << ":\n";

        
        cout << "Enter credit hours: ";
        cin >> credit;

        
        cout << "Enter grade point (e.g. 4.0, 3.3, 2.7): ";
        cin >> gradePoint;

    
        totalCredits += credit;
        totalGradePoints += credit * gradePoint;
    }

    
    float cgpa = totalGradePoints / totalCredits;

    
    cout << fixed << setprecision(2);
    cout << "\nTotal Credit Hours: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}

