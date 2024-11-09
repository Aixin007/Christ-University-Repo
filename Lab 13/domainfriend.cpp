#include <iostream>  
#include <string>  

using namespace std;  

const int MAX_CERTIFICATIONS = 100; // Define maximum number of certifications  

class Certification {  
private:  
    string name;  
    string issuer;  
    int duration; // in hours  

public:  
    Certification() : name(""), issuer(""), duration(0) {} // Default constructor  

    Certification(string _name, string _issuer, int _duration)   
        : name(_name), issuer(_issuer), duration(_duration) {}  

    void display() const {  
        cout << "Certification: " << name << endl;  
        cout << "Issued by: " << issuer << endl;  
        cout << "Duration: " << duration << " hours" << endl;  
    }  

    // Declare a friend function to update issuer name  
    friend void updateIssuer(Certification& cert, const string& newIssuer);  

    // Friend class to access private members  
    friend class CertificationManager;  
};  

void updateIssuer(Certification& cert, const string& newIssuer) {  
    cert.issuer = newIssuer; // Update the issuer of the certification  
}  

class CertificationManager {  
private:  
    Certification certifications[MAX_CERTIFICATIONS]; // Array of Certifications  
    int count; // Current number of certifications  

public:  
    CertificationManager() : count(0) {} // Initialize count  

    void addCertification(const Certification& cert) {  
        if (count < MAX_CERTIFICATIONS) {  
            certifications[count++] = cert; // Store the certification  
        } else {  
            cout << "Cannot add more certifications. Maximum limit reached." << endl;  
        }  
    }  

    void viewCertifications() {  
        if (count == 0) {  
            cout << "No certifications available." << endl;  
            return;  
        }  
        for (int i = 0; i < count; i++) {  
            certifications[i].display();  
            cout << "------------------------" << endl;  
        }  
    }  

    // Optionally, a function to allow updating the issuer for a certification  
    void setIssuer(int certIndex, const string& newIssuer) {  
        if (certIndex >= 0 && certIndex < count) {  
            updateIssuer(certifications[certIndex], newIssuer); // Using the friend function  
            cout << "Issuer updated successfully!" << endl;  
        } else {  
            cout << "Invalid certification index!" << endl;  
        }  
    }  

    // Public method to get the current count of certifications  
    int getCount() const {  
        return count;  
    }  
};  

void displayMenu() {  
    cout << "Online Certification Management System" << endl;  
    cout << "1. Add Certification" << endl;  
    cout << "2. View Certifications" << endl;  
    cout << "3. Update Issuer" << endl;  
    cout << "4. Exit" << endl;  
}  

int main() {  
    CertificationManager manager;  
    int choice;  

    do {  
        displayMenu();  
        cout << "Choose an option: ";  
        cin >> choice;  

        switch (choice) {  
            case 1: {  
                string name, issuer;  
                int duration;  

                cout << "Enter Certification Name: ";  
                cin.ignore(); // Clear the newline from the buffer  
                getline(cin, name);  
                cout << "Enter Issuer Name: ";  
                getline(cin, issuer);  
                cout << "Enter Duration (hours): ";  
                cin >> duration;  

                Certification cert(name, issuer, duration);  
                manager.addCertification(cert);  
                cout << "Certification added successfully!" << endl;  
                break;  
            }  
            case 2:  
                manager.viewCertifications();  
                break;  
            case 3: {  
                int index;  
                string newIssuer;  

                cout << "Enter Certification Index to Update Issuer (0 to " << manager.getCount() - 1 << "): ";  
                cin >> index;  
                cout << "Enter New Issuer Name: ";  
                cin.ignore(); // Clear the newline from the buffer  
                getline(cin, newIssuer);  

                manager.setIssuer(index, newIssuer);  
                break;  
            }  
            case 4:  
                cout << "Exiting..." << endl;  
                break;  
            default:  
                cout << "Invalid option! Please try again." << endl;  
        }  

    } while (choice != 4);  

    return 0;  
}