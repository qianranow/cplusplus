//
// Created by qianranow on 2022/2/25.
//

#include <iostream>
#include <string>
using namespace std;

//lambda表达式：[capture](parameters) opt -> retType{}
//推荐使用使用：[=](){}的形式

//调用方式：使用函数指针
void test01()
{

    void (*p)() = [](){cout << "hello, lambda~" << endl;};
    p();
}

//外部局部变量捕获
//捕获局部变量分两种方式，一种是值传递，一种是引用
//默认情况下值传递捕获进来的局部变量就是const
void test02()
{
    int a = 10;
    int b = 20;
    [a, &b]() mutable
    {
        a = 30;
        b = 30;
    }();
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}

//=：局部变量全部使用值传递捕获进来，包括this
void test03()
{
    int a = 10;
    int b = 20;
    int c = 10;
    int d = 20;
    int e = 10;
    int f = 20;
    [=]()
    {
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }();
}

//&：局部变量全部使用引用传递捕获进来，包括this
void test04()
{
    int a = 10;
    int b = 20;
    int c = 10;
    int d = 20;
    int e = 10;
    int f = 20;
    [&]()
    {
        a = 30;
        b = 30;
    }();
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}

//混合方式
void test05()
{
    int a = 10;
    int b = 20;
    int c = 10;
    int d = 20;
    int e = 10;
    int f = 20;
    [&, b]() mutable
    {
        a = 30;
        b = 30;
    }();
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
}
//->retType：标识lambda函数返回值的类型。这部分可以省略，但是省略了并不代表函数没有返回值，
//编译器会自动根据函数体内的return语句判断返回值类型，但是如果有多条return语句，而且返回的
//类型都不一样，编译会报错。
void test06()
{
    int a = 10;
//    [=]() mutable
//    {
//        int b = 20;
//        float c = 30.0;
//        if (a > 0)
//        {
//            return b;
//        }
//        else
//        {
//            return c;//err；编译报错，两条return语句返回类型不一致
//        }
//    }();
}

int main()
{
    test06();
    return 0;
}