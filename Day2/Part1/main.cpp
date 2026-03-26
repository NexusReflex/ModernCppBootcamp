#include <iostream>
#include "StudentGradeProcessor.h"

using namespace StudentGradeProcessor;

int main() {
    std::vector<Student> students = {
        {"Alice", 85.5},
        {"Bob", 92.0},
        {"Eve", 40.0},
        {"Charlie", 78.0},
        {"Doloris", 50.0},
        {"James", 94.5}
    };

    sort_by_grade_descending(students);

    std::cout << "-- Students in descending order --" << std::endl;
    for (const auto& student : students) {
        std::cout << "Name: " << student.name << ", Grade: " << student.grade << std::endl;
    }

    auto top_student = *findTopStudent(students);

    if (top_student.name.empty()) {
        std::cout << "\nNo student with a grade above 90.0 found." << std::endl;
    } else {
        std::cout << "\nTop student: " << top_student.name << ", Grade: " << top_student.grade << std::endl;
    }

    auto number_failed_students = countFailedStudents(students);

    std::cout << "\nNumber of failed students: " << number_failed_students << std::endl;
    
    auto failed_students = findFailedStudents(students);

    if (failed_students.empty()) {
        std::cout << "\nNo failed students found." << std::endl;
    } else {
        std::cout << "\nFailed students:" << std::endl;
        for (const auto& student : failed_students) {
            std::cout << "Name: " << student.name << ", Grade: " << student.grade << std::endl;
        }
    }

    sort_by_grade_ascending(students);

    std::cout << "\n-- Students in ascending order --" << std::endl;
    for (auto student : students){
        std::cout << "Name: " << student.name << ", Grade: " << student.grade << std::endl;
    }

    return 0;
}