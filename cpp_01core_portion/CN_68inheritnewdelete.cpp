//
// Created by qianranow on 2022/2/11.
//

#include <iostream>
using namespace std;

class Father
{
public:
    Father()
    {
        cout << "father构造函数" << endl;
    }
    ~Father()
    {
        cout << "father析构函数" << endl;
    }
};

class Son : public Father
{
public:
    Son()
    {
        cout << "son构造函数" << endl;
    }
    ~Son()
    {
        cout << "son析构函数" << endl;
    }
};

//先调用父类的构造函数，再调用本身的构造函数，析构函数调用顺序反之
void test01()
{
    Son s;
}

class A
{
public:
    A()
    {
        cout << "A的构造" << endl;
    }
    ~A()
    {
        cout << "A的析构" << endl;
    }

public:
    Son s;
};

class B
{
public:
    B()
    {
        cout << "B的构造" << endl;
    }
    ~B()
    {
        cout << "B的析构" << endl;
    }
};

class C
{
public:
    C()
    {
        cout << "C的构造" << endl;
    }
    ~C()
    {
        cout << "C的析构" << endl;
    }
};

//继承和组合混搭
//先调用父类的构造，然后调用成员对象的构造，最后调用本身的构造，析构函数调用顺序反之
class D : public A
{
public:
    D()
    {
        cout << "D的构造" << endl;
    }
    ~D()
    {
        cout << "D的析构" << endl;
    }

public:
    B b;
    C c;
};

void test02()
{
    D d;
}

int main()
{
    test02();
    return 0;
}