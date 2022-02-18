//
// Created by qianranow on 2022/1/27.
//

#include <iostream>

using namespace std;

int myFunc(int a, int b=0)
{
    return a + b;
}

void test01()
{
    cout << myFunc(10, 20) << endl;
    cout << myFunc(10) << endl;
}

//注意1：函数的默认参数后面的参数必须都是默认参数
int myFunc2(int a, int b = 0, int c = 2, int d = 3)
{
    return a + b + c + d;
}
//注意2：函数的声明和实现不能同时有函数的默认参数
void myFunc3(int a, int b);
void myFunc3(int a, int b = 0)
{

}

//函数的占位参数，占位参数在后面运算符重载时区分前加加或后加加
void func(int a, int=10) //占位参数也有默认值
{

}

void test02()
{
    func(10, 20);
}

void func2(int=10, int a=20)
{

}
void test03()
{
    func2();
    func2(10);
    func2(10,30);
}

int main()
{
    test01();
    return 0;
}