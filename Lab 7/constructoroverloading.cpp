#include <iostream>
#include <string>
#include <map>
#include <vector>

class Course {
public:
    enum Category { PROGRAMMING, DATA_SCIENCE, WEB_DEVELOPMENT, MACHINE_LEARNING, ALGORITHMS };

private:
    std::string name;
    Category category;
    int difficulty; // 1-5
    int duration; // Duration in hours
    std::string instructor;
    std::vector<std::string> prerequisites;
    double rating; // 1.0 - 5.0

public:
    // Default constructor
    Course()
        : name("Unknown"), category(PROGRAMMING), difficulty(1), duration(1), instructor("Unknown"), rating(0.0) {}

    // Constructor for basic course with just a name
    Course(const std::string& name)
        : name(name), category(PROGRAMMING), difficulty(1), duration(1), instructor("Unknown"), rating(0.0) {}

    // Constructor for course with name and category
    Course(const std::string& name, Category category)
        : name(name), category(category), difficulty(1), duration(1), instructor("Unknown"), rating(0.0) {}

    // Constructor for course with name, category, and difficulty
    Course(const std::string& name, Category category, int difficulty)
        : name(name), category(category), difficulty(difficulty), duration(1), instructor("Unknown"), rating(0.0) {}

    // Constructor for course with all details
    Course(const std::string& name, Category category, int difficulty, int duration, const std::string& instructor, const std::vector<std::string>& prerequisites, double rating)
        : name(name), category(category), difficulty(difficulty), duration(duration), instructor(instructor), prerequisites(prerequisites), rating(rating) {}

    void displayInfo() const {
        std::cout << "Course Name: " << name << "\n"
                  << "Category: " << categoryToString(category) << "\n"
                  << "Difficulty: " << difficulty << "\n"
                  << "Duration: " << duration << " hours\n"
                  << "Instructor: " << instructor << "\n"
                  << "Rating: " << rating << "\n"
                  << "Prerequisites: ";
        for (const auto& prereq : prerequisites) {
            std::cout << prereq << " ";
        }
        std::cout << "\n";
    }

    static std::string categoryToString(Category category) {
        switch (category) {
            case PROGRAMMING: return "Programming";
            case DATA_SCIENCE: return "Data Science";
            case WEB_DEVELOPMENT: return "Web Development";
            case MACHINE_LEARNING: return "Machine Learning";
            case ALGORITHMS: return "Algorithms";
            default: return "Unknown";
        }
    }

    std::string getName() const {
        return name;
    }

    Category getCategory() const {
        return category;
    }
};

class CourseCatalog {
private:
    std::map<std::string, Course> courses;

public:
    void addCourse(const Course& course) {
        courses[course.getName()] = course;
    }

    void displayCourseNames() const {
        for (const auto& pair : courses) {
            std::cout << pair.first << "\n";
        }
    }
};

void addCourseInteractive(CourseCatalog& catalog) {
    std::string name, instructor;
    int category, difficulty, duration;
    double rating;
    std::vector<std::string> prerequisites;
    std::string prereq;

    std::cout << "Enter course name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter category (0: Programming, 1: Data Science, 2: Web Development, 3: Machine Learning, 4: Algorithms): ";
    std::cin >> category;

    std::cout << "Enter difficulty (1-5): ";
    std::cin >> difficulty;

    std::cout << "Enter duration (in hours): ";
    std::cin >> duration;

    std::cout << "Enter instructor name: ";
    std::cin.ignore();
    std::getline(std::cin, instructor);

    std::cout << "Enter rating (1.0 - 5.0): ";
    std::cin >> rating;

    std::cout << "Enter prerequisites (type 'done' to finish): ";
    std::cin.ignore();
    while (true) {
        std::getline(std::cin, prereq);
        if (prereq == "done") break;
        prerequisites.push_back(prereq);
        std::cout << "Enter prerequisites (type 'done' to finish): ";
    }

    catalog.addCourse(Course(name, static_cast<Course::Category>(category), difficulty, duration, instructor, prerequisites, rating));
}

int main() {
    CourseCatalog catalog;
    int choice;

    do {
        std::cout << "1. Add Course\n";
        std::cout << "2. Display All Course Names\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addCourseInteractive(catalog);
                std::cout << "Course added successfully!\n";
                std::cout << "Updated Course List:\n";
                catalog.displayCourseNames();
                break;
            case 2:
                std::cout << "Courses in Catalog:\n";
                catalog.displayCourseNames();
                break;
            case 3:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}


