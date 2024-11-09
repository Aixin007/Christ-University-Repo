#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstdio>
#include <sstream>

namespace std {}  

using namespace std;

class opencourseware
{
public:
    int stud_id;
    string stud_name;
    string course_name;
    float project_mark;
    vector<int> module_mark;
    float final_test;

    // Default constructor with user input
    opencourseware()
    {
        string input;
        stringstream ss;

        cout << "Enter Student ID (press Enter for default 1000): ";
        getline(cin, input);
        if (input.empty()) {
            stud_id = 1000;
        } else {
            ss << input;
            ss >> stud_id;
            ss.clear();
        }

        cout << "Enter Student Name (press Enter for default 'New Student'): ";
        getline(cin, stud_name);
        if (stud_name.empty()) stud_name = "New Student";

        cout << "Enter Course Name (press Enter for default 'Introduction to C++'): ";
        getline(cin, course_name);
        if (course_name.empty()) course_name = "Introduction to C++";

        cout << "Enter project mark (0-20, press Enter for default 10.0): ";
        getline(cin, input);
        if (input.empty()) {
            project_mark = 10.0f;
        } else {
            ss << input;
            ss >> project_mark;
            ss.clear();
        }
        while (project_mark < 0 || project_mark > 20) {
            cout << "Invalid Input. Enter between 0-20: ";
            cin >> project_mark;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter the number of module tests (press Enter for default 3): ";
        getline(cin, input);
        int n;
        if (input.empty()) {
            n = 3;
        } else {
            ss << input;
            ss >> n;
            ss.clear();
        }
        module_mark.resize(n);
        cout << "Enter Module Test Marks: ";
        for (int i = 0; i < n; ++i) {
            cin >> module_mark[i];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Final Test Marks (0-20, press Enter for default 15.0): ";
        getline(cin, input);
        if (input.empty()) {
            final_test = 15.0f;
        } else {
            ss << input;
            ss >> final_test;
            ss.clear();
        }
        while (final_test < 0 || final_test > 20) {
            cout << "Invalid Input. Enter between 0-20: ";
            cin >> final_test;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << endl;
    }

    // Parameterized constructor with user input
    opencourseware(int id, const string& name, const string& course)
        : stud_id(id), stud_name(name), course_name(course)
    {
        cout << "Enter project mark (0-20): ";
        cin >> project_mark;
        while (project_mark < 0 || project_mark > 20) {
            cout << "Invalid Input. Enter between 0-20: ";
            cin >> project_mark;
        }

        cout << "Enter the number of module tests: ";
        int n;
        cin >> n;
        module_mark.resize(n);
        cout << "Enter Module Test Marks: ";
        for (int i = 0; i < n; ++i) {
            cin >> module_mark[i];
        }

        cout << "Enter Final Test Marks (0-20): ";
        cin >> final_test;
        while (final_test < 0 || final_test > 20) {
            cout << "Invalid Input. Enter between 0-20: ";
            cin >> final_test;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
    }

    // Copy constructor
    opencourseware( opencourseware& other)
        : stud_id(other.stud_id), stud_name(other.stud_name),
          course_name(other.course_name), project_mark(other.project_mark),
          module_mark(other.module_mark), final_test(other.final_test)
    {
    }

    void displayInfo()
    {
        cout << "Student ID: " << stud_id << endl;
        cout << "Student Name: " << stud_name << endl;
        cout << "Course Name: " << course_name << endl;
        cout << "Project Mark: " << project_mark << endl;
        cout << "Number of Module Tests: " << module_mark.size() << endl;
        cout << "Module Test Marks: ";
        for (size_t i = 0; i < module_mark.size(); ++i) {
            cout << module_mark[i] << " ";
        }
        cout << endl;
        cout << "Final Test Mark: " << final_test << endl;
        cout << endl;
    }
};

int main()
{
    // Default Constructor
    cout << "Creating a student with default constructor:" << endl;
    opencourseware defaultStudent;
    cout << "Values after creation:" << endl;
    defaultStudent.displayInfo();
    
    // Parameterized Constructor
    cout << "Creating a student with parameterized constructor:" << endl;
    int id;
    string name, course;

    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter Course Name: ";
    getline(cin, course);

    opencourseware parameterizedStudent(id, name, course);
    cout << "Values after creation:" << endl;
    parameterizedStudent.displayInfo();
    
    // Copy Constructor
    cout << "Creating a copy of the parameterized student:" << endl;
    opencourseware copiedStudent(parameterizedStudent);
    cout << "Values of the copied student:" << endl;
    copiedStudent.displayInfo(); 

    return 0;
}
