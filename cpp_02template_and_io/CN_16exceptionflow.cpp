//
// Created by qianranow on 2022/2/22.
//

#include <iostream>
using namespace std;

int func(int a, int b)
{
    if (b == 0)
    {
        throw 10;//第二步
        cout << "throw后的代码" << endl;
    }
    return a / b;
}

void test()
{
    int a = 10;
    int b = 0;
    try
    {
        func(a, b);//第一个步
        cout << "func后的代码" << endl;
    }
    catch (int)//第三步
    {
        cout << "接收一个int类型的异常" << endl;
    }
}

int main()
{
    test();
    return 0;
}