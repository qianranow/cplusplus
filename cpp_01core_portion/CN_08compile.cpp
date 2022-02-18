//
// Created by qianranow on 2022/1/26.
//

#include <iostream>

using namespace std;
void test()
{
    int a = 10;
    // 如果用变量给const修饰的局部变量赋值，那么编译器不会优化
    const int b = a;
    int *p = (int *)&b;
    *p = 100;
    cout << "b=" << b << endl;
    cout << "*p=" << *p << endl;
}
struct Maker
{
    Maker()
    {
        a = 100;
    }
    int a;
};

void test02()
{
    const Maker ma;
    cout << ma.a << endl;
    Maker *p = (Maker *)&ma;
    p->a = 200;
    cout << ma.a << endl; // 没有优化，因为不能优化自定义数据类型
}

int main()
{
    test();
    return 0;
}