//
// Created by qianranow on 2022/1/26.
//

#include <iostream>

using namespace std;
const int aa = 10; //没有内存

void test01()
{
    // 常量折叠
    cout << "aa=" << aa << endl; // 在编译阶段，编译器：cout << "aa=" << 10 << endl;
    // 禁止优化
    volatile const int bb = 20;
    int *p = (int *)&bb;
    *p = 200;
    cout << "bb=" << bb << endl; // cout << "bb=" << 20 << endl;
    cout << "bb=" << *p << endl;

    printf("bb的地址=%p\n", &bb);
    cout << "p指向的地址" << p << endl;
}

int main()
{
    test01();
    // c++语言中const修饰的全局变量具有内部链接属性
    extern const int c;
    cout << "c=" << c << endl;
    return 0;
}