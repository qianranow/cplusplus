//
// Created by qianranow on 2022/2/19.
//

#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType>
class Maker
{
public:
    Maker(NameType name, AgeType age);
//    {
//        this->name = name;
//        this->age = age;
//    }
    void printMaker();
//    {
//        cout << "Name:" << this->name << "Age:" << this->age << endl;
//    }
public:
    NameType name;
    AgeType age;
};

//类模板的成员函数类外实现
//要写成函数模板
template<class NameType, class AgeType>
Maker<NameType, AgeType>::Maker(NameType name, AgeType age)
{
    cout << "构造函数" << endl;
    this->name = name;
    this->age = age;
}

template<class NameType, class AgeType>
void Maker<NameType, AgeType>::printMaker()
{
    cout << "Name:" << this->name << "Age:" << this->age << endl;
}

int main()
{
    Maker<string, int> m("haha", 20);
    m.printMaker();
    return 0;
}