#include <iostream>  
#include <string>  
#include <vector>  
#include <unordered_map>  
using namespace std;  

// Function to display the menu  
void displayMenu() {  
    cout << "1. Register for a Course" << endl;  
    cout << "2. Recommend Courses" << endl;  
    cout << "3. Track Progress" << endl;  
    cout << "4. Exit" << endl;  
    cout << endl;  
}  


void registerCourse(string courseName, string studentName) {  
    cout << endl;  
    cout << studentName << " registered for course: " << courseName << endl;  
    cout << endl;  
}  

 
void registerCourse(string courseName) {  
    cout << endl;  
    cout << "A student registered for course: " << courseName << endl;  
    cout << endl;  
}  

// Function to recommend courses  
void recommendCourses() {  
    unordered_map<string, vector<string>> courseRecommendations = {  
        {"AI", {"Introduction to AI", "Machine Learning Basics", "Deep Learning"}},  
        {"Web Development", {"HTML & CSS", "JavaScript Essentials", "React for Beginners"}},  
        {"Programming", {"C++ Fundamentals", "Python for Data Science", "Java Programming"}}  
    };  

    string interest;  
    cout << "Enter your area of interest (AI, Web Development, Programming): ";  
    getline(cin, interest);  

    if (courseRecommendations.find(interest) != courseRecommendations.end()) {  
        cout << endl;  
        cout << "Recommended Courses for " << interest << ":" << endl;  
        for (const auto& course : courseRecommendations[interest]) {  
            cout << "- " << course << endl;  
        }  
    } else {  
        
        cout << endl;  
        cout << "No recommendations available for the entered interest." << endl;  
    }  
    cout << endl;  
}  

// Function to track progress  
void trackProgress(const unordered_map<string, int>& progress) {  
    cout << endl;  
    cout << "Your Course Progress:" << endl;  
    cout << endl;  
    for (const auto& entry : progress) {  
        cout << "Course: " << entry.first << " - " << entry.second << "% completed" << endl;  
    }  
    cout << endl;  
}  

int main() {  
    int choice;  
    string courseName, studentName;  
    unordered_map<string, int> progress = {{"Introduction to AI", 50}, {"HTML & CSS", 75}, {"C++ Fundamentals", 30}};  // order of the data doesn't matter  

    while (true) {  
        displayMenu();  
        cout << "Enter your choice: ";  
        cin >> choice;  
        cin.ignore(); // Clear the newline character from the buffer  

        switch (choice) {  
            case 1:  
                cout << "Enter course name: ";  
                getline(cin, courseName);  
                cout << "Enter student name (press Enter to continue without registering a name): ";  
                getline(cin, studentName);  
                // Check if studentName is empty and call the appropriate overloaded function  
                if (studentName.empty()) {  
                    registerCourse(courseName); // Call the overload without studentName  
                } else {  
                    registerCourse(courseName, studentName); // Call the overload with studentName  
                }  
                break;  
            case 2:  
                recommendCourses();  
                break;  
            case 3:  
                trackProgress(progress);  
                break;  
            case 4:  
                cout << "Exiting..." << endl;  
                return 0;  
            default:  
                cout << "Invalid choice. Please try again." << endl;  
        }  
    }  

    return 0;  
}