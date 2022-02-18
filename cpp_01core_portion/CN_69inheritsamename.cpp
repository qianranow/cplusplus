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
        a = 10;
    }
    void func()
    {
        cout << "father func" << endl;
    }
    void func(int a)
    {
        cout << "father func(int a)" << endl;
    }
    void func(int a, int b)
    {
        cout << "father func(int a, int b)" << endl;
    }
public:
    int a;
};

class Son : public Father
{
public:
    Son()
    {
        a = 20;
    }
    void func()
    {
        cout << "son func" << endl;
    }
public:
    int a;
};

//当子类和父类有同名成员时，子类的同名成员会隐藏父类的同名成员
void test()
{
    Son s;
    cout << s.a << endl;
    cout << sizeof(Son) << endl;
    //通过父类名加作用域来访问
    cout << s.Father::a << endl;
}

//当子类有和父类同名函数时，父类的所有函数重载都会被隐藏
void test02()
{
    Son s;
    s.func();
    //s.func(10);err
    //s.func(10, 20);err
    //通过作用域来访问隐藏的父类函数
    s.Father::func();
    s.Father::func(10);
    s.Father::func(10, 20);
}

int main()
{
    test02();
    return 0;
}