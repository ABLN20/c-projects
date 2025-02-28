#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

// Represents a student and the courses they are enrolled in
struct Student {
    std::string name;
    std::set<std::string> courses;
};

// Represents a course and the timeslots it is scheduled in
struct Course {
    std::string name;
    std::set<std::string> timeslots;
};

// Finds scheduling conflicts for a student
void findConflicts(const Student& student, const std::map<std::string, Course>& courseSchedule) {
    std::multiset<std::string> timeslotCount;

    // Collect all timeslots for the student's courses
    for (const auto& course : student.courses) {
        // TODO, iterate through the students courseSchedule to find each course, copy all the time slots of the course to the timeSlot Count. Hint, use std::copy and std::inserter
        auto it = courseSchedule.find(course);
        if (it != courseSchedule.end()) 
        {
            const auto& course = it->second;
            std::copy(course.timeslots.begin(), course.timeslots.end(),
            std::inserter(timeslotCount, timeslotCount.end()));
        }
    }

    // Find and print any scheduling conflicts
    std::set<std::string> conflictSlots;
    // TODO - iterate through the timeslotCount, if there are multiple, add it to conflictSlots
    for (const auto& slot : timeslotCount) 
    {
        if (timeslotCount.count(slot) > 1) 
        {
            conflictSlots.insert(slot);
        }
    }

    if (!conflictSlots.empty()) {
        std::cout << "Scheduling conflicts for " << student.name << ":\n";
        for (const auto& slot : conflictSlots) {
            std::cout << " - Timeslot: " << slot << "\n";
        }
    } else {
        std::cout << "No scheduling conflicts for " << student.name << "\n";
    }
}

int main() {
    // Sample data for students
    std::vector<Student> students = {
        {"Alice", {"Math101", "CS102"}},
        {"Bob", {"Math101", "History201"}},
        {"Charlie", {"CS102", "History201"}}
    };

    // Sample data for courses and their timeslots
    std::map<std::string, Course> courseSchedule = {
        {"Math101", {"Math101", {"Mon 9am", "Wed 9am"}}},
        {"CS102", {"CS102", {"Mon 9am", "Fri 10am"}}},
        {"History201", {"History201", {"Wed 9am", "Fri 12pm"}}}
    };

    // Find conflicts for each student
    for (const auto& student : students) {
        findConflicts(student, courseSchedule);
    }

    return 0;
}
 