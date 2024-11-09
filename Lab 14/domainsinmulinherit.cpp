#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
using namespace std;

// Base Class: Course
class Course {
protected:
    string courseName;
    string courseLevel;
public:
    Course(string name, string level) : courseName(name), courseLevel(level) {}
    
    virtual void displayCourse() const {
        cout << "Course: " << courseName << ", Level: " << courseLevel << endl;
    }
    
    virtual string getCategory() const { return ""; }
    string getCourseName() const { return courseName; }
    
    virtual string toJSON() const {
        return "{\"courseName\": \"" + courseName + "\", \"courseLevel\": \"" + courseLevel + "\"}";
    }
};

// Single Inheritance: Category
class Category : public Course {
protected:
    string categoryName;
public:
    Category(string name, string level, string category) : Course(name, level), categoryName(category) {}
    
    void displayCourse() const override {
        cout << "Category: " << categoryName << " -> ";
        Course::displayCourse();
    }
    
    string getCategory() const override { return categoryName; }
    
    string toJSON() const override {
        return "{\"categoryName\": \"" + categoryName + "\", " + Course::toJSON().substr(1);
    }
};

// Multilevel Inheritance: RecommendedCourse
class RecommendedCourse : public Category {
private:
    string recommendationReason;
public:
    RecommendedCourse(string name, string level, string category, string reason)
        : Category(name, level, category), recommendationReason(reason) {}

    void displayCourse() const override {
        cout << "Recommended because: " << recommendationReason << " -> ";
        Category::displayCourse();
    }
    
    string toJSON() const override {
        return "{\"recommendationReason\": \"" + recommendationReason + "\", " + Category::toJSON().substr(1);
    }
};

// User Class with Progress Tracking
class User {
private:
    string userName;
    map<string, int> completedCourses; // course name -> score
public:
    User(string name) : userName(name) {}

    void completeCourse(const std::string& courseName, int score) {
        completedCourses[courseName] = score;
    }

    void displayProgress(const vector<unique_ptr<RecommendedCourse>>& allCourses) const {
        if (completedCourses.empty()) {
            cout << "You haven't completed any courses yet.\n";
            return;
        }

        cout << "\nUser: " << userName << "'s Progress:\n";
        for (const auto& course : allCourses) {
            auto it = completedCourses.find(course->getCourseName());
            if (it != completedCourses.end()) {
                int score = it->second;  // Get the score from the completedCourses map
                cout << "You completed the course \"" << course->getCourseName()
                     << "\" with a score of " << score 
                     << " in the " << course->getCategory() << " category." << endl;
            }
        }
    }

    string getUserName() const {
        return userName;
    }

    string toJSON() const {
        string json = "{\"userName\": \"" + userName + "\", \"completedCourses\": {";
        for (const auto& course : completedCourses) {
            json += "\"" + course.first + "\": " + to_string(course.second) + ",";
        }
        if (!completedCourses.empty()) {
            json.back() = '}';  // replace the last comma with closing brace
        } else {
            json += "}";  // If empty, close the courses object
        }
        return json + "}";
    }

    bool hasCompleted(const string& courseName) const {
        return completedCourses.find(courseName) != completedCourses.end();
    }
};

// Load Courses from File
vector<unique_ptr<RecommendedCourse>> loadCourses(const string& filename) {
    ifstream file(filename);
    vector<unique_ptr<RecommendedCourse>> courses;

    if (!file.is_open()) {
        cerr << "Could not open the file: " << filename << endl;
        return courses;
    }

    // Dummy logic for loading from file (this part can be replaced by real parsing logic)
    courses.push_back(make_unique<RecommendedCourse>("C++ Basics", "Beginner", "Programming", "Interest in Programming"));
    courses.push_back(make_unique<RecommendedCourse>("Data Structures", "Intermediate", "Programming", "Completed Basics"));
    courses.push_back(make_unique<RecommendedCourse>("Machine Learning", "Advanced", "AI", "High Score in Math"));

    return courses;
}

// Save Courses to File
void saveCourses(const string& filename, const vector<unique_ptr<RecommendedCourse>>& courses) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Could not open the file for writing: " << filename << endl;
        return;
    }

    for (const auto& course : courses) {
        file << course->toJSON() << endl;
    }
}

// Load User Progress from File
User loadUserProgress(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open the user progress file: " << filename << endl;
        return User("Unknown");  // Return a default user if file can't be opened
    }

    string name;
    getline(file, name);
    User user(name);

    string courseName;
    int score;
    while (file >> ws && getline(file, courseName, ',') >> score) {
        user.completeCourse(courseName, score);
    }
    return user;
}

// Save User Progress to File
void saveUserProgress(const string& filename, const User& user) {
    ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file for saving progress: " << filename << std::endl;
        return;
    }
    file << user.toJSON() << std::endl;
}

// Main Function with Enhanced User Options
int main() {
    User user = loadUserProgress("user_progress.txt");
    vector<unique_ptr<RecommendedCourse>> courses = loadCourses("courses.txt");

    int choice;
    do {
        cout << "\nWelcome,\n";
        cout << "1. View your course progress\n";
        cout << "2. Get recommended courses by category\n";
        cout << "3. Complete a course and update your score\n";
        cout << "4. View all available courses\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // View progress
                user.displayProgress(courses);
                break;
            }
            case 2: {
                // Get recommendations based on category
                int categoryChoice;
                cout << "Choose a category for recommendations:\n1. Programming\n2. AI\n";
                cin >> categoryChoice;

                auto displayCategory = [&courses, &user](const string& category) {
                    for (const auto& course : courses) {
                        if (course->getCategory() == category && !user.hasCompleted(course->getCourseName())) {
                            course->displayCourse();
                        }
                    }
                };

                switch (categoryChoice) {
                    case 1:
                        displayCategory("Programming");
                        break;
                    case 2:
                        displayCategory("AI");
                        break;
                    default:
                        cout << "Invalid category choice!" << endl;
                }
                break;
            }
            case 3: {
                // Complete a course and update the score
                string courseName;
                int score;
                cout << "Enter the course name you have completed: ";
                cin.ignore();  // Clear the input buffer
                getline(cin, courseName);
                cout << "Enter your score for " << courseName << ": ";
                cin >> score;

                if (!user.hasCompleted(courseName)) {
                    user.completeCourse(courseName, score);
                    cout << "Course " << courseName << " completed with score: " << score << std::endl;

                    // Display updated progress
                    cout << "\nUpdated Progress:\n";
                    user.displayProgress(courses);
                } else {
                    cout << "You have already completed this course!" << endl;
                }

                break;
            }
            case 4: {
                // View all available courses
                cout << "Available courses:\n";
                for (const auto& course : courses) {
                    course->displayCourse();
                }
                break;
            }
            case 5:
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please select a valid option.\n";
        }

        // Save user progress and courses after any updates
        saveUserProgress("user_progress.txt", user);
        saveCourses("courses.txt", courses);

    } while (choice != 5);  // Loop until the user chooses to exit

    return 0;
}









