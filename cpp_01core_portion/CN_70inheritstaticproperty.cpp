//
// Created by qianranow on 2022/2/11.
//

#include <iostream>
using namespace std;

class Father
{
public:
    static void func()
    {
        cout << "father func" << endl;
    }
    static void func(int a)
    {
        cout << "father func(int a)" << endl;
    }
    static void func(int a, int b)
    {
        cout << "father func(int a, int b)" << endl;
    }

public:
    static int mA;
};
int Father::mA = 10;

class Son : public Father
{
public:
//    static void func()
//    {
//        cout << "son func" << endl;
//    }
//    static int func()
//    {
//        cout << "in func" << endl;
//    }
public:
    static  int mA;
};
int Son::mA = 20;

void test01()
{
    Son s;
    //1.静态成员可以被继承
    //2.继承中的静态成员变量一样会被同名的子类成员变量隐藏
    //3.继承中的静态成员函数中，当子类有和父类同名静态函数时，父类的所有重载静态函数都会被隐藏
    //4.改变从基类继承过来的静态函数的某个特征，返回值或者参数个数，将会隐藏基类重载的函数
    //5.静态成员函数不能是虚函数
    //6.从父类继承过来的静态成员变量是父类的静态成员变量
    //7.构造，析构和赋值函数都不能被继承
    cout << s.mA << endl;
    s.Father::mA = 200;
    cout << Father::mA << endl;
    cout << &(s.Father::mA) << endl;
    cout << &(Father::mA) << endl;
//    s.func();
//    s.func(10);
//    cout << s.Father::mA << endl;
//    cout << s.mB << endl;
}

int main()
{
    test01();
    return 0;
}