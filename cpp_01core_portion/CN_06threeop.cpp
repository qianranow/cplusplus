//
// Created by qianranow on 2022/1/26.
//

#include <iostream>

using namespace std;

void test01()
{
    int a = 10;
    int b = 20;
    (a > b ? a : b) = 100;
    // c++的三目运算符返回的是左值，是空间
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}

int main()
{
    test01();
    return 0;
}