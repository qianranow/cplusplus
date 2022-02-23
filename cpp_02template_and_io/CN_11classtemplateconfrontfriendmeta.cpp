//
// Created by qianranow on 2022/2/21.
//

#include <iostream>
#include <string>
using namespace std;

template<class NameTyep, class AgeType>
class Maker
{
    //友元在类内实现
    friend void printMaker(Maker<NameTyep, AgeType> &p)
    {
        cout << "类内实现" << p.name << " " << p.age << endl;
    }

public:
    Maker(NameTyep name, AgeType age)
    {
        this->name = name;
        this->age = age;
    }

private:
    NameTyep name;
    AgeType age;
};

void test01()
{
    Maker<string, int> m("悟空", 18);
    printMaker(m);
}

//1.声明类模板
template<class NameTyep, class AgeType>
class Maker2;
//2.声明函数模板
//告诉编译器下面有printMaker2的实现
template<class NameTyep, class AgeType>
void printMaker2(Maker2<NameTyep, AgeType> &p);
template<class NameTyep, class AgeType>
class Maker2
{
    //3.在函数名和()之间加上<>
    friend void printMaker2<>(Maker2<NameTyep, AgeType> &p);
    //编译器不知道printMaker2下面有没有实现，需要知道函数的结构
public:
    Maker2(NameTyep name, AgeType age)
    {
        this->name = name;
        this->age = age;
    }

private:
    NameTyep name;
    AgeType age;
};

//4.友元在类外实现要写成函数模板
template<class NameTyep, class AgeType>
void printMaker2(Maker2<NameTyep, AgeType> &p)
{
    cout << "类外实现的友元函数" << p.name << " " << p.age << endl;
}

void test02()
{
    Maker2<string, int> m("贝吉塔", 18);
    printMaker2(m);
}


int main()
{
    test02();
    return 0;
}