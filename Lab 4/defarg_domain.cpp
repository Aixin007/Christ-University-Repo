#include <iostream>
#include <string>
#include <vector>

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

public:
    // Default constructor with default arguments
    opencourseware(int id = 1000, const string& name = "New Student", const string& course = "Introduction to C++",
                   float project = 10.0, const vector<int>& module = {70, 70, 70}, float final = 15.0)
        : stud_id(id), stud_name(name), course_name(course), project_mark(project), module_mark(module), final_test(final)
    {
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
    }

    float calculateOverallScore()
    {
        int sum = 0;
        for (int i = 0; i < module_mark.size(); ++i)
        {
            sum += module_mark[i];
        }
        float average = static_cast<float>(sum) / module_mark.size();

        float overallScore = 0.4 * project_mark + 0.5 * average + 0.1 * final_test;
        return overallScore;
    }

    void generateCertificate(string studentName, string courseName, float overallScore = 0.0)
    {
        float average = calculateOverallScore();

        if (project_mark < 14 && average < 75 && final_test < 16)
        {
            cout << "Certificate issuance declined. Student did not pass." << endl;
        }
        else
        {
            cout << "----------------------------------------" << endl;
            cout << "CERTIFICATE OF COMPLETION" << endl;
            cout << "Course: " << courseName << endl;
            cout << "Student: " << studentName << endl;
            cout << "Weighted Score: " << overallScore << endl;
            cout << "Congratulations! You have successfully completed the course." << endl;
            cout << "----------------------------------------" << endl;
        }
    }
};

int main()
{
   
    opencourseware default_student;
    default_student.report();

    float overallScore = default_student.calculateOverallScore();
    default_student.generateCertificate(default_student.stud_name, default_student.course_name, overallScore);

    vector<int> custom_module_marks = {85, 90, 95};
    opencourseware custom_student(1234, "Alex King", "Artificial Intelligence", 18.5, custom_module_marks, 19.0);
    custom_student.report();

    overallScore = custom_student.calculateOverallScore();
    custom_student.generateCertificate(custom_student.stud_name, custom_student.course_name, overallScore);

    return 0;
}

