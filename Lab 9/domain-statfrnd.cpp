#include <iostream>  
#include <string>  
using namespace std;  

// Class to represent a course  
class Course {  
private:  
    string courseName;  
    string instructor;  
    int duration; // in weeks  
    int credits;  
    
    static int courseCount; // Static member to count the number of courses  

public:  
    // Constructor overloading  
    Course() : courseName("Unknown"), instructor("Unknown"), duration(0), credits(0) {  
        courseCount++; // Increment count when a new course is created  
    } // Default constructor  

    Course(string name, string instr, int dur, int cred) // Parameterized constructor  
        : courseName(name), instructor(instr), duration(dur), credits(cred) {  
        courseCount++; // Increment count when a new course is created  
    }  

    // Destructor to decrement course count  
    ~Course() {  
        courseCount--; // Decrement count when a course is destroyed (optional)  
    }  

    // Function to set course details (call by const reference)  
    void setCourseDetails(const string& name, const string& instr, int dur, int cred) {  
        courseName = name;  
        instructor = instr;  
        duration = dur;  
        credits = cred;  
    }  

    // Static function to get the total number of courses  
    static int getCourseCount() {  
        return courseCount;  
    }  

    // Friend function to display course details  
    friend void displayCourse(const Course& course);  
};  

// Initialize static member  
int Course::courseCount = 0;  

// Friend function to display course details  
void displayCourse(const Course& course) {  
    cout << "Course: " << course.courseName   
         << "\nInstructor: " << course.instructor   
         << "\nDuration: " << course.duration << " weeks"   
         << "\nCredits: " << course.credits << "\n";  
}  

// Function to display the main menu  
void displayMenu() {  
    cout << "\n--- OpenCourseWare Certification Platform ---\n";  
    cout << "1. Display Course Details\n";  
    cout << "2. Add New Course\n";  
    cout << "3. Display Total Courses That Can Be Taken\n";  
    cout << "4. Exit\n";  
    cout << "Enter your choice: ";  
}  

// Function to add course details using an array of objects  
void addNewCourse(Course courses[], int& count) {  
    string name, instructor;  
    int duration, credits;  

    cout << "Enter course name: ";  
    cin.ignore();  
    getline(cin, name);  

    cout << "Enter instructor name: ";  
    getline(cin, instructor);  

    cout << "Enter course duration (weeks): ";  
    cin >> duration;  
    while (duration <= 0) {  
        cout << "Duration must be a positive number. Enter again: ";  
        cin >> duration;  
    }  

    cout << "Enter course credits: ";  
    cin >> credits;  
    while (credits <= 0) {  
        cout << "Credits must be a positive number. Enter again: ";  
        cin >> credits;  
    }  

    courses[count].setCourseDetails(name, instructor, duration, credits);  
    count++;  
}  

int main() {  
    Course courses[10]; // Array of objects to store up to 10 courses  
    int courseCount = 0;  
    int choice;  


    do {  
        displayMenu();  
        cin >> choice;  

        switch (choice) {  
            case 1: {  
                if (courseCount > 0) {  
                    cout << "\nCourse Details:\n";  
                    for (int i = 0; i < courseCount; i++) {  
                        cout << "-------------------------\n";  
                        displayCourse(courses[i]);  
                    }  
                } else {  
                    cout << "No courses available.\n";  
                }  
                break;  
            }  

            case 2: {  
                if (courseCount < 10) {  
                    addNewCourse(courses, courseCount);  
                    cout << "Course added successfully.\n";  
                } else {  
                    cout << "Course limit reached.\n";  
                }  
                break;  
            }  

            case 3:  
                cout << "Total number of courses that can be taken: " << Course::getCourseCount() << endl;  
                break;  

            case 4:  
                cout << "Exiting...\n";  
                break;  

            default:  
                cout << "Invalid choice. Please try again.\n";  
        }  
    } while (choice != 4);  

    return 0;  
}


