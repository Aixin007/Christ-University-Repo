#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Course {
private:
    string courseName;
    int credits;

public:
    // Constructor
    Course(string name = "", int cr = 0) : courseName(name), credits(cr) {}

    // Function to set course details
    void setCourse(string name, int cr) {
        courseName = name;
        credits = cr;
    }

    // Getter for course name
    string getCourseName() const {
        return courseName;
    }

    // Getter for course credits
    int getCredits() const {
        return credits;
    }

    // Display function
    void display() const {
        cout << "Course: " << courseName << ", Credits: " << credits << endl;
    }
};

class CourseList {
private:
    vector<Course> courses;  // Using vector for dynamic course storage

public:
    // Add course
    void addCourse(const Course& course) {
        courses.push_back(course);
    }

    // Overloading the subscript operator for array-like access
    Course& operator[](int index) {
        if (index < 0 || index >= courses.size()) {
            throw out_of_range("Index out of bounds!");
        }
        return courses[index];
    }

    // Display all courses
    void displayAll() const {
        if (courses.empty()) {
            cout << "No courses available to display.\n";
        } else {
            for (size_t i = 0; i < courses.size(); ++i) {
                cout << "Course " << (i + 1) << ": ";
                courses[i].display();
            }
        }
    }

    // Sort courses by credits
    void sortByCredits() {
        sort(courses.begin(), courses.end(), [](const Course& a, const Course& b) {
            return a.getCredits() > b.getCredits();  // Sort descending by credits
        });
        cout << "Courses sorted by credits.\n";
    }

    // Sort courses by name
    void sortByName() {
        sort(courses.begin(), courses.end(), [](const Course& a, const Course& b) {
            return a.getCourseName() < b.getCourseName();  // Sort alphabetically by name
        });
        cout << "Courses sorted by name.\n";
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Enter Course Details\n";
    cout << "2. Display All Courses\n";
    cout << "3. Sort Courses by Credits\n";
    cout << "4. Sort Courses by Name\n";
    cout << "5. Modify Course Details by Index\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    CourseList courseList;
    int choice, index, credits, numCourses;
    string name;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:  // Enter course details
                cout << "How many courses do you want to add? ";
                cin >> numCourses;

                for (int i = 0; i < numCourses; ++i) {
                    cout << "Enter name for course " << (i + 1) << ": ";
                    cin >> ws;  // To consume any leading whitespace
                    getline(cin, name);
                    cout << "Enter credits for course " << (i + 1) << ": ";
                    cin >> credits;
                    Course course(name, credits);
                    courseList.addCourse(course);  // Adding the course to the vector
                }
                break;

            case 2:  // Display all courses
                courseList.displayAll();
                break;

            case 3:  // Sort by credits
                courseList.sortByCredits();
                break;

            case 4:  // Sort by name
                courseList.sortByName();
                break;

            case 5:  // Modify specific course by index
                cout << "Enter index of course to modify (starting from 0): ";
                cin >> index;
                try {
                    cout << "Enter new name for course: ";
                    cin >> ws;  // To consume any leading whitespace
                    getline(cin, name);
                    cout << "Enter new credits for course: ";
                    cin >> credits;
                    courseList[index].setCourse(name, credits);  // Using subscript operator overload
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;

            case 6:  // Exit
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}


