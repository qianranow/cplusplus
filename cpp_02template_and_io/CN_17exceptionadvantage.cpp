//
// Created by qianranow on 2022/2/22.
//

#include <iostream>
using namespace std;
//异常的优势
//1.用户不知道返回值是什么意思，异常可以抛出对象，对象中可以包含很多成员函数，可以有很多信息
//2.返回值用户可以忽略，但异常不能忽略，如果忽略给你报错
//3.返回值只能返回一条信息，但是对象有成员函数，可以包含多个信息
//4.逐层依赖处理异常
class Maker
{
public:
    void printMaker()
    {
        cout << "除数不能为0" << endl;
    }
};

int func(int a, int b)
{
    if (b == 0)
    {
        //Maker m;
        //throw m;
        throw 20.22;
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
    catch (Maker maker)
    {
        cout << "接收一个Maker类型的异常" << endl;
        maker.printMaker();
    }
    catch (double s)
    {
        //不想处理异常，可以往上抛出，抛给调用本函数的函数
        throw;
    }
}


int main()
{
    try
    {
        test();
    }
    catch (double d)
    {
        cout << "接收一个double类型的异常" << endl;
    }
    return 0;
}