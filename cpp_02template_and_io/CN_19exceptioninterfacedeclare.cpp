//
// Created by qianranow on 2022/2/22.
//

#include <iostream>
using namespace std;

void func() throw(int, char)//只允许抛出int或者char异常
{
    throw 10;
}

int main()
{
    try
    {
        func();
    }
    catch (int)
    {
        cout << "int" << endl;
    }
    catch (...)
    {
        cout << "..." << endl;
    }
    return 0;
}