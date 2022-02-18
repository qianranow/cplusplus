//
// Created by qianranow on 2022/1/26.
//

#include <iostream>

using namespace std;

int main()
{
    // 1.引用创建时，必须初始化
    // 2.引用一旦初始化不能改变它的指向
    int a = 10;
    int &pRef = a;
    int b = 20;
    pRef = b; // 赋值操作

    cout << &a << endl;
    cout << &pRef << endl;

    return 0;
}