#include <iostream>
using namespace std;

class Marks {
private:
    int mark;

public:
    // Constructor
    Marks(int m = 0) : mark(m) {}

    // Unary operator overloading
    Marks operator-() const { // Unary minus to negate the mark
        return Marks(mark-1);
    }

    Marks operator++() { // Prefix increment to increase the mark
        ++mark;
        return *this;
    }

    Marks operator++(int) { // Postfix increment to increase the mark
        Marks temp = *this;
        mark++;
        return temp;
    }

    // Binary operator overloading
    Marks operator+(const Marks& other) const { // Addition of marks
        return Marks(mark + other.mark);
    }

    Marks operator-(const Marks& other) const { // Subtraction of marks
        return Marks(mark - other.mark);
    }

    Marks operator*(const Marks& other) const { // Multiplication of marks
        return Marks(mark * other.mark);
    }

    // Display function
    void display() const {
        cout << "Mark: " << mark << endl;
    }

    // Function to set mark
    void setMark(int m) {
        mark = m;
    }
};

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Enter Marks\n";
    cout << "2. Negate Marks\n";
    cout << "3. Increment Marks (Prefix)\n";
    cout << "4. Increment Marks (Postfix)\n";
    cout << "5. Add Marks\n";
    cout << "6. Subtract Marks\n";
    cout << "7. Multiply Marks\n";
    cout << "8. Display Marks\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Marks marks[3];
    Marks result;
    int choice, index, value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < 3; ++i) {
                    cout << "Enter mark for student " << i + 1 << ": ";
                    cin >> value;
                    marks[i].setMark(value);
                }
                break;
            case 2:
                cout << "Enter index of mark to negate (0-2): ";
                cin >> index;
                if (index >= 0 && index < 3) {
                    result = -marks[index];
                    result.display();
                } else {
                    cout << "Invalid index!\n";
                }
                break;
            case 3:
                cout << "Enter index of mark to increment (prefix) (0-2): ";
                cin >> index;
                if (index >= 0 && index < 3) {
                    ++marks[index];
                    marks[index].display();
                } else {
                    cout << "Invalid index!\n";
                }
                break;
            case 4:
                cout << "Enter index of mark to increment (postfix) (0-2): ";
                cin >> index;
                if (index >= 0 && index < 3) {
                    marks[index]++;
                    marks[index].display();
                } else {
                    cout << "Invalid index!\n";
                }
                break;
            case 5:
                cout << "Enter indices of marks to add (0-2): ";
                int index1, index2;
                cin >> index1 >> index2;
                if (index1 >= 0 && index1 < 3 && index2 >= 0 && index2 < 3) {
                    result = marks[index1] + marks[index2];
                    result.display();
                } else {
                    cout << "Invalid indices!\n";
                }
                break;
            case 6:
                cout << "Enter indices of marks to subtract (0-2): ";
                cin >> index1 >> index2;
                if (index1 >= 0 && index1 < 3 && index2 >= 0 && index2 < 3) {
                    result = marks[index1] - marks[index2];
                    result.display();
                } else {
                    cout << "Invalid indices!\n";
                }
                break;
            case 7:
                cout << "Enter indices of marks to multiply (0-2): ";
                cin >> index1 >> index2;
                if (index1 >= 0 && index1 < 3 && index2 >= 0 && index2 < 3) {
                    result = marks[index1] * marks[index2];
                    result.display();
                } else {
                    cout << "Invalid indices!\n";
                }
                break;
            case 8:
                for (int i = 0; i < 3; ++i) {
                    cout << "Mark for student " << i + 1 << ": ";
                    marks[i].display();
                }
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
