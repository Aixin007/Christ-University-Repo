#include <iostream>
#include <string>
#include <vector>

using namespace std;

class opencourseware
{
    int stud_id;
    string stud_name;
    string course_name;
    float project_mark;
    vector<int> module_mark;
    float final_test;

public:
    void readValues()
    {
        cout << "Enter Student ID: ";
        cin >> stud_id;
        cin.ignore();

        cout << "Enter Student Name: ";
        getline(cin, stud_name);

        cout << "Enter Course Name: ";
        getline(cin, course_name);

        do {
            cout << "Enter project mark (0-20): ";
            cin >> project_mark;
            if (project_mark < 0 || project_mark > 20) {
                cout << "Invalid Input. Enter between 0-20" << endl;
            }
        } while (project_mark < 0 || project_mark > 20);

        int n;
        cout << "Enter the number of module test marks: ";
        cin >> n;

        module_mark.resize(n);
        cout << "Enter Module Test Marks: ";
        for (int i = 0; i < n; ++i)
        {
            cin >> module_mark[i];
        }

        do {
            cout << "Enter Final Test Marks: ";
            cin >> final_test;
            if (final_test < 0 || final_test > 20) {
                cout << "Invalid Input. Enter between 0-20" << endl;
            }
        } while (final_test < 0 || final_test > 20);

        cout << endl;
    }

    void report()
    {
        int sum = 0;

        for (int i = 0; i < module_mark.size(); ++i)
        {
            sum += module_mark[i];
        }

        float average = static_cast<float>(sum) / module_mark.size();

        if (project_mark < 14 && average < 75 && final_test < 16)
        {
            cout << "Result: Failed. Please retry." << endl;
        }
        else
        {
            cout << "Result: Wohoo! Passed." << endl;
        }

        display_grade();
    }

    void display_grade()
    {
        float score;
        int sum = 0;

        for (int i = 0; i < module_mark.size(); ++i)
        {
            sum += module_mark[i];
        }

        float average = static_cast<float>(sum) / module_mark.size();

        score = average + project_mark + final_test;

        char grade;

        if (score >= 90)
        {
            grade = 'A';
        }
        else if (score >= 80)
        {
            grade = 'B';
        }
        else if (score >= 70)
        {
            grade = 'C';
        }
        else if (score >= 60)
        {
            grade = 'D';
        }
        else
        {
            grade = 'F';
        }

        cout << "Grade: " << grade << endl;
    }
};

int main()
{
    opencourseware x;
    x.readValues();
    x.report();
    return 0;
}

