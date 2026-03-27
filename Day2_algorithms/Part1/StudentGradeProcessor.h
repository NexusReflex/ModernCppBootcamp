#pragma once

#include <string>
#include <vector>
#include <algorithm>


namespace StudentGradeProcessor {
    
    struct Student{
        std::string name;
        double grade;
    };

    // Sorts students in descending order by grades
    void sort_by_grade_descending(std::vector<Student>& students){
        std::sort(students.begin(), students.end(), [](const auto& a, const auto& b){
            return a.grade > b.grade;
        });
    };

    
    // Finds the first student with a grade above 90.0. Returns an iterator to the student, or students.end() if no such student is found.
    auto findTopStudent(std::vector<Student>& students){
        return std::find_if(students.begin(), students.end(), [](const auto& a){
            return a.grade > 90.0;
        });
    };

    auto countFailedStudents(std::vector<Student>& students){
        return std::count_if(students.begin(), students.end(), [](const auto& a){
            return a.grade <= 50.0;
        });
    };

    // Returns a std::vector<Student> containing all students with a grade below 50.0. If no such students are found, returns an empty vector.
   
    auto findFailedStudents(const std::vector<Student>& students){
        std::vector<Student> failedStudents;
        std::copy_if(students.begin(), students.end(), std::back_inserter(failedStudents), [](const auto& a){
            return a.grade <= 50.0;
        });
        if (failedStudents.empty()) {
            return std::vector<Student>{};
        }
        return failedStudents;
    };

    /// Example to implement above with std::ranges. This let's us pass the whole container instead of having to to specify .begin(), .end()
    void sort_by_grade_ascending(std::vector<Student>& students){
        std::ranges::sort(students, [](const auto& a, const auto& b){
            return a.grade < b.grade;
        });
    };
}