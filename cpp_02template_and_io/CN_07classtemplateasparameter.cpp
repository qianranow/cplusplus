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
    Maker(NameType name, AgeType age)
    {
        this->name = name;
        this->age = age;
    }
    void printMaker()
    {
        cout << "Name:" << this->name << "Age:" << this->age << endl;
    }
public:
    NameType name;
    AgeType age;
};

//1.指定传入的数据类型
void func(Maker<string, int> &m)
{
    m.printMaker();
}

//2.参数模板化(常用)
template<class T1, class T2>
void func2(Maker<T1, T2> &m)
{
    m.printMaker();
}

//3.整个类 模板化
template<class T>
void func3(T &m)
{
    m.printMaker();
}

void test()
{
    Maker<string, int> m1("悟空", 18);
    func(m1);
    func2(m1);//调用时进行第二次编译
    func3(m1);
}


int main()
{
    test();
    return 0;
}