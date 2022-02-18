//
// Created by qianranow on 2022/2/8.
//

#include <iostream>
using namespace std;
//1.空类的大小是1，不是0
class Maker
{

};

void test01()
{
    cout << sizeof(Maker) << endl;
    Maker *m = new Maker[20];//为什么空类是1，因为编译器从内存更好区分对象
}

//2.类的成员函数不占用类的大小，静态成员变量不占用类的大小，静态成员函数不占用类的大小
class Maker2
{
public:
    void func()//成员函数不占用类的大小
    {
        b = 20;
        cout << b << endl;
    }
    static int a;//静态成员变量不占用类的大小
    static void func2()//静态成员函数不占用类的大小
    {

    }
    int b;//3.普通成员变量占用类的大小
    //4.类的成员中，成员函数和成员变量是分开存储
};

int Maker2::a = 100;

void test02()
{
    cout << sizeof(Maker2) << endl;
    Maker2 m2;
    m2.func();
    cout << sizeof(m2) << endl;
}

int main()
{
    test02();
    return 0;
}