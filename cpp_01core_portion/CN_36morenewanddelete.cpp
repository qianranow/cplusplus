//
// Created by qianranow on 2022/2/7.
//

#include <iostream>
using namespace std;

class BMW
{
public:
    BMW(int a)
    {
        cout << "BMW有参构造" << a << endl;
    }

    ~BMW()
    {
        cout << "BMW析构" << endl;
    }
};

class Buick
{
public:
    Buick(int b, int c)
    {
        cout << "Buick构造" << b << c << endl;
    }

    ~Buick()
    {
        cout << "Buick析构" << endl;
    }
};

class Maker
{
public:
    //初始化列表
    //主要：初始化列表只能写在构造函数
//    Maker() :bmw(10)
//    {
//        cout << "Maker构造" << endl;
//    }
    //如果有多个对象需要指定调用某个构造函数，用逗号隔开
    Maker(int a, int b, int c) :bmw(a), bui(b, c)
    {
        cout << "Maker构造" << endl;
    }
    //注意2：如果使用了初始化列表，那么所有的构造函数都要写初始化列表
    Maker(const Maker &m2) :bmw(40), bui(20, 30)
    {

    }
    ~Maker()
    {
        cout << "Maker析构" << endl;
    }
private:
    BMW bmw;
    Buick bui;
};

//1.如果类有成员对象，那么先调用成员对象的构造函数，再调用本身的构造函数
//析构函数的调用顺序反之
//2.成员对象的构造函数调用和定义顺序一样
//3.注意，如果有成员对象，那么实例化对象时，必选保证成员对象的构造和析构能被调用
//void test01()
//{
//    Maker m;
//}

//初始化列表是调用成员对象的指定构造函数
void test02()
{
    Maker m(10, 20, 30);
}

int main()
{
    test02();
    return 0;
}