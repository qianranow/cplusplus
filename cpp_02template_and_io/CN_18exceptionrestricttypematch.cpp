//
// Created by qianranow on 2022/2/22.
//

#include <iostream>
using namespace std;

int func(int a, int b)
{
    if (b == 0)
    {
        //throw 20.22;
        //throw 'c';
        throw 20.0f;
    }
    return a / b;
}

void test()
{
    int a = 10;
    int b = 0;
    try
    {
        func(a, b);
    }
    catch (int)
    {
        cout << "接收一个int类型的异常" << endl;
    }

    catch (double s)
    {
        cout << "接收一个double类型的异常" << endl;
    }

    catch (char s)
    {
        cout << "接收一个char类型的异常" << endl;
    }

    catch (...)//接收其他类型的异常
    {
        cout << "接收一个其他类型的异常" << endl;
    }
}
int main()
{
    test();
    return 0;
}