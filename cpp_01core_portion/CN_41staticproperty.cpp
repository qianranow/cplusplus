//
// Created by qianranow on 2022/2/7.
//

#include <iostream>
using namespace std;

class Maker
{
public:
    Maker()
    {

    }
public:
    //1.静态成员变量的生命周期是整个程序，作用域在类内
    static int a;
};
//2.静态成员变量要在类内声明，类外初始化
int Maker::a = 200;
void test01()
{
    //3.静态成员变量属于类，不属于对象，是所有对象共享
    cout << Maker::a << endl;
    Maker m;
    cout << m.a << endl;
    //4.静态成员变量可以用类访问，也可以用对象访问
}

class Maker2
{
public:
    Maker2()
    {

    }
    //5.静态成员函数只能访问静态成员变量
    static void setA(int a)
    {
        a2 = a;
        cout << "a2=" << a2 << endl;
        //a1 = a;不能访问普通成员变量
    }
public:
    int a1;
    static int a2;
};
int Maker2::a2 = 200;

void test02()
{
    Maker2::setA(300);
}

class Maker3
{
public:
    //6.静态成员也有权限，如果为私有，类外也不可以访问
    static void func()
    {
        cout << "a3=" << a3 << endl;
    }
private:
    static int a3;
};
int Maker3::a3 = 300;

void test03()
{
    Maker3::func();
    Maker3 m;
    //m.a3; err
}

//7.const修饰的静态成员变量最好在类内初始化
class Maker4
{
public:
    const static int a = 20;
    const static int b;
};
//类外也可以初始化
const int Maker4::b = 30;

class Maker5
{
public:
    //8.普通成员函数可以访问静态成员变量
    void func()
    {
        cout << "a=" << a << endl;
    }
public:
    static int a;

};

int Maker5::a = 30;

void test04()
{
    Maker5 m;
    m.func();
}

int main()
{
    test04();
    return 0;
}