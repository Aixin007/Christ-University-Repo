#include <iostream>  
#include <string>  
#include <algorithm> // For using find_if-standard library
#include <vector> // For using vector
using namespace std;
// Class representing a Course  
class Course {  
private:  
    string courseName;  
    int courseID;  

public:  
    // Constructor  
    Course(const string& name, int id) : courseName(name), courseID(id) {  
        cout << "Course created: " << courseName << " (ID: " << courseID << ")\n";  
    }  

    // Destructor  
    ~Course() {  
        cout << "Course destroyed: " << courseName << " (ID: " << courseID << ")\n";  
    }  

    // Display course details  
    void display() const {  
        cout << "Course Name: " << courseName << ", Course ID: " << courseID << "\n";  
    }  

    int getID() const {  
        return courseID;  
    }  

    const string& getName() const {  
        return courseName;  
    }  
};  

// Class representing a CourseList  
class CourseList {  
private:  
    vector<Course*> courses; // Change to vector for dynamic size  

public:  
    // Constructor  
    CourseList(int n) {  
        for (int i = 0; i < n; ++i) {  
            string name;  
            int id;  
            cout << "Enter name for course " << i + 1 << ": ";
            cin.ignore(); // To ignore the newline character left in the buffer  
            getline(cin, name);  
            cout << "Enter ID for course " << i + 1 << ": ";  
            cin >> id;  
            courses.push_back(new Course(name, id));  
        }  
    }  

    // Destructor  
    ~CourseList() {  
        for (Course* course : courses) {  
            delete course;  
        }  
        cout << "All courses destroyed.\n";  
    }  

    // Add a new course  
    void addCourse(const string& name, int id) {  
        courses.push_back(new Course(name, id));  
    }  

    // Delete a course by ID  
    void deleteCourse(int id) {  
        auto it = find_if(courses.begin(), courses.end(),  
            [id](Course*course) { return course->getID() == id; });  

        if (it != courses.end()) {  
            delete *it;  
            courses.erase(it);  
            cout << "Course with ID " << id << " deleted.\n";  
        } else {  
            cout << "Course with ID " << id << " not found.\n";  
        }  
    }  

    // Display all courses  
    void displayAll() const {  
        if (courses.empty()) {  
            cout << "No courses available.\n";  
            return;  
        }  
        for (const Course* course : courses) {  
            course->display();  
        }  
    }  

    // Search courses by keyword  
    void searchCourseByName(const string& keyword) const {  
        cout << "Searching for courses containing: " << keyword << "\n";  
        bool found = false;  
        for (const Course* course : courses) {  
            if (course->getName().find(keyword) != string::npos) {  
                course->display();  
                found = true;  
            }  
        }  
        if (!found) {  
            cout << "No courses found containing: " << keyword << "\n";  
        }  
    }  
};  

int main() {  
    int numCourses;  
    cout << "Enter the initial number of courses: ";  
    cin >> numCourses;  

    CourseList courseList(numCourses);  

    int choice;  
    do {  
        cout << "\nMenu:\n";  
        cout << "1. Display all courses\n";  
        cout << "2. Add a new course\n";  
        cout << "3. Delete a course by ID\n";  
        cout << "4. Search courses by name\n"; // New option  
        cout << "5. Exit\n";  
        cout << "Enter your choice: ";  
        cin >> choice;  

        switch (choice) {  
            case 1:  
                courseList.displayAll();  
                break;  
            case 2: {  
                string name;  
                int id;  
                cout << "Enter course name: ";  
                cin.ignore(); // To ignore the newline character left in the buffer  
                getline(cin, name);  
                cout << "Enter course ID: ";  
                cin >> id;  
                courseList.addCourse(name, id);  
                break;  
            }  
            case 3: {  
                int id;  
                cout << "Enter course ID to delete: ";  
                cin >> id;  
                courseList.deleteCourse(id);  
                break;  
            }  
            case 4: { // New case for searching courses  
                string keyword;  
                cout << "Enter a keyword to search for courses: ";  
                cin.ignore(); // To ignore the newline character left in the buffer  
                getline(cin, keyword);  
                courseList.searchCourseByName(keyword);  
                break;  
            }  
            case 5:  
                cout << "Exiting...\n";  
                break;  
            default:  
                cout << "Invalid choice. Please try again.\n";  
        }  
    } while (choice != 5);  

    return 0;  
}


