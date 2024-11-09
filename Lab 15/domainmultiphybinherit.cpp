#include <iostream>
#include <string>
using namespace std;

// Base class for User
class User {
protected:
    string name;
    int age;
public:
    void setUserDetails(string n, int a) {
        name = n;
        age = a;
    }
    void displayUserDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Base class for Course
class Course {
protected:
    string courseName;
public:
    void setCourseDetails(string cn) {
        courseName = cn;
    }
    void displayCourseDetails() {
        cout << "Course: " << courseName << endl;
    }
};

// Derived class for Certification inheriting from User and Course (Multiple Inheritance)
class Certification : public User, public Course {
private:
    string certificationName;
public:
    void setCertificationDetails(string cn) {
        certificationName = cn;
    }
    void displayCertificationDetails() {
        displayUserDetails();
        displayCourseDetails();
        cout << "Certification: " << certificationName << endl;
    }
};

// Another base class for Platform
class Platform {
protected:
    string platformName;
public:
    void setPlatformDetails(string pn) {
        platformName = pn;
    }
    void displayPlatformDetails() {
        cout << "Platform: " << platformName << endl;
    }
};

// Derived class for OnlineCertificationPlatform inheriting from Certification and Platform (Hybrid Inheritance)
class OnlineCertificationPlatform : public Certification, public Platform {
public:
    void displayAllDetails() {
        displayCertificationDetails();
        displayPlatformDetails();
    }
};

int main() {
    int numUsers;
    cout << "Enter the number of students: ";
    cin >> numUsers;
    cin.ignore(); // To ignore the newline character left by cin

    OnlineCertificationPlatform* ocpArray = new OnlineCertificationPlatform[numUsers];
    int choice;
    string name, course, certification, platform;
    int age;

    for (int i = 0; i < numUsers; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Enter User Name: ";
        getline(cin, name);
        cout << "Enter User Age: ";
        cin >> age;
        cin.ignore(); // To ignore the newline character left by cin

        cout << "Enter Course Name: ";
        getline(cin, course);
        cout << "Enter Certification Name: ";
        getline(cin, certification);
        cout << "Enter Platform Name: ";
        getline(cin, platform);

        ocpArray[i].setUserDetails(name, age);
        ocpArray[i].setCourseDetails(course);
        ocpArray[i].setCertificationDetails(certification);
        ocpArray[i].setPlatformDetails(platform);
    }

    cout << "\nChoose an option to display details:\n";
    cout << "1. User Details\n";
    cout << "2. Course Details\n";
    cout << "3. Certification Details\n";
    cout << "4. Platform Details\n";
    cout << "5. All Details\n";
    cout << "Enter your choice: ";
    cin >> choice;

    for (int i = 0; i < numUsers; ++i) {
        cout << "\nDetails for student " << i + 1 << ":\n";
        switch (choice) {
            case 1:
                ocpArray[i].displayUserDetails();
                break;
            case 2:
                ocpArray[i].displayCourseDetails();
                break;
            case 3:
                ocpArray[i].displayCertificationDetails();
                break;
            case 4:
                ocpArray[i].displayPlatformDetails();
                break;
            case 5:
                ocpArray[i].displayAllDetails();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    delete[] ocpArray; // Free the allocated memory

    return 0;
}
  
