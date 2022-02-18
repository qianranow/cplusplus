//
// Created by qianranow on 2022/1/26.
//

#include <iostream>

using namespace std;

struct Maker
{
    char name[64];
    int age;
};

void test01()
{
    Maker a; // 不需要加 struct 就可以定义变量
};

struct Maker2
{
    int a;
    // 可以写函数
    void func() {
        cout << "func" << endl;
    }
};

void test02()
{
    Maker2 a2;
    a2.func();
}

int main()
{
    test02();
    return 0;
}