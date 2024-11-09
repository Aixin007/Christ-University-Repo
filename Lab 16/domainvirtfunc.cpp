#include <iostream>  
#include <string>  
#include <vector>  
using namespace std;  

// Base class for User  
class User {  
protected:  
    string name;  
    int age;  
public:  
    virtual void setUserDetails(const string& n, int a) {  
        name = n;  
        age = a;  
    }  
    virtual void displayUserDetails() const {  
        cout << "Name: " << name << ", Age: " << age << endl;  
    }  
    virtual ~User() = default; // Virtual destructor  
};  

// Base class for Course  
class Course {  
protected:  
    string courseName;  
public:  
    virtual void setCourseDetails(const string& cn) {  
        courseName = cn;  
    }  
    virtual void displayCourseDetails() const {  
        cout << "Course: " << courseName << endl;  
    }  
    virtual ~Course() = default; // Virtual destructor  
};  

// Derived class for Certification inheriting from User and Course  
class Certification : public User, public Course {  
protected:  
    string certificationName;  
public:  
    virtual void setCertificationDetails(const string& cn) = 0; // Pure virtual function  
    virtual void displayCertificationDetails() const = 0; // Pure virtual function  

    virtual ~Certification() = default; // Virtual destructor  
};  

// Another base class for Platform  
class Platform {  
protected:  
    string platformName;  
public:  
    virtual void setPlatformDetails(const string& pn) {  
        platformName = pn;  
    }  
    virtual void displayPlatformDetails() const {  
        cout << "Platform: " << platformName << endl;  
    }  
    virtual ~Platform() = default; // Virtual destructor  
};  

// Derived class for OnlineCertificationPlatform inheriting from Certification and Platform  
class OnlineCertificationPlatform : public Certification, public Platform {  
public:  
    virtual void setCertificationDetails(const string& cn) override {  
        certificationName = cn;  
    }  

    virtual void displayCertificationDetails() const override {  
        displayUserDetails();  
        displayCourseDetails();  
        cout << "Certification: " << certificationName << endl;  
    }  

    virtual void displayAllDetails() const {  
        displayCertificationDetails();  
        displayPlatformDetails();  
    }  
};  

int main() {  
    int numUsers;  
    cout << "Enter the number of students: ";  
    cin >> numUsers;  
    cin.ignore(); // To ignore the newline character left by cin  

    vector<OnlineCertificationPlatform> ocpArray(numUsers);  
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
    int choice;  
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

    return 0;  
}


