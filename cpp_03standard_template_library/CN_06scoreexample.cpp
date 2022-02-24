//
// Created by qianranow on 2022/2/24.
//

#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class Student
{
public:
    string name;
    int mScore;
};

void CreateStudent(vector<Student> &vstu)
{
    string setName = "ABCDE";
    for (int i = 0; i < 5; ++i) {
        Student stu;
        stu.name = "学生";
        stu.name += setName[i];
        stu.mScore = 0;
        vstu.push_back(stu);
    }
}
void SetScore(vector<Student> &vstu)
{
    srand((unsigned int)time(NULL));
    for (vector<Student>::iterator it = vstu.begin(); it != vstu.end(); ++it)
    {
        deque<int> dScore;
        for (int i = 0; i < 10; ++i) {
            int score = rand()%70+30;
            dScore.push_back(score);
        }
        sort(dScore.begin(), dScore.end());
        dScore.pop_back();
        dScore.pop_front();
        int total = 0;
        for (deque<int>::iterator sit=dScore.begin(); sit!=dScore.end(); ++sit)
        {
            total += (*sit);
        }
        int averageScore = total / dScore.size();
        it->mScore = averageScore;
    }
}

//谓词
bool myCompare(Student &s1, Student &s2)
{
    return s1.mScore > s2.mScore;
}

void ShowStudentScore(vector<Student> &vstu)
{
    sort(vstu.begin(), vstu.end(), myCompare);
    for (vector<Student>::iterator it = vstu.begin(); it!=vstu.end(); ++it)
    {
        cout << "Name:" << it->name << "Score:" << it->mScore << endl;
    }
}

void test()
{
    vector<Student> vstu;
    CreateStudent(vstu);
    SetScore(vstu);
    ShowStudentScore(vstu);
}

int main()
{
    test();
    return 0;
}