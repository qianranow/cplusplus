//
// Created by qianranow on 2022/1/27.
//

#include <iostream>
#include <string>
using namespace std;

class Student
{
public: //公有权限
    void setName(string Name)
    {
        name = Name;
    }
    void setId(int Id)
    {
        id = Id;
    }
    void myprint()
    {
        cout << "姓名:" << name << "\n学号:" << id << endl;
    }
private: //私有权限
    string name;
    int id;
};

int main()
{
    Student s;
    s.setName("贝吉塔");
    s.setId(1);
    s.myprint();
    return 0;
}