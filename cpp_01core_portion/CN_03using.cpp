//
// Created by qianranow on 2022/1/26.
//

#include <iostream>

using namespace std;

namespace A
{
    int a = 10;
    int b = 20;
    int c = 30;
}

void test01()
{
    // using声明是让命名空间中某个标识符可以直接使用
    using A::a;
    cout << a << endl;

}

void test02()
{
    // using编译指令，让某个命名空间中的标识符都可以直接使用
    using namespace A;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    int a = 100; // 不会冲突
    // 类于命名空间中的a是全局变量，这里的a是局部变量
    cout << a << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}