//
// Created by qianranow on 2022/2/10.
//

#include <iostream>
using namespace std;

class Maker
{
public:
    Maker(int id, int age)
    {
        this->id = id;
        this->age = age;
    }
    //写成成员函数，那么只需要一个参数，这个参数是加号的右边
    Maker operator+(Maker &m2) const
    {
        Maker tmp(this->id + m2.id, this->age + m2.age);
        return tmp;
    }
public:
    int id;
    int age;
};

//全局方式 //3.编译器调用这个函数
//Maker operator+(Maker &p1, Maker &p2)//2.编译器检查参数是否对应，第一个参数是加号的左边，第二个参数是加号的右边
//{
//    Maker tmp(p1.id + p2.id, p1.age + p2.age);
//    return tmp;
//}

void test01()
{
    Maker m1(1, 20);
    Maker m2(2, 22);
    //+也叫双目运算符
    Maker m3 = m1 + m2;//1.编译器看到两个对象相加，那么编译器会去找有没有叫operator+的函数
    cout << "id:" << m3.id << "\nage:" << m3.age << endl;
    //复数加
    Maker m4 = m1 + m2 + m3;
    cout << "id:" << m4.id << "\nage:" << m4.age << endl;
}

class Student
{
public:
    Student()
    {
        mid = 0;
    }
    Student(int id)
    {
        mid = id;
    }
public:
    int mid;
};

Student operator+(Maker &m, Student &s)
{
    Student tmp(m.id + s.mid);
    return tmp;
}
void test()
{
    Maker m1(1, 18);
    Student s1(2);
    Student s2 = m1 + s1;
    cout << "id:" << s2.mid << endl;
}

int main()
{
    test();
    return 0;
}
