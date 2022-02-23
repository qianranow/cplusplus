//
// Created by qianranow on 2022/2/22.
//

#include <iostream>
using namespace std;

class Father
{
public:
    virtual void printM()
    {

    }
};

//1.有继承
class SonNULL : public Father
{
public:
    virtual void printM()//2.重写父类的虚函数
    {
        cout << "空指针异常" << endl;
    }
};

class SonOut : public Father
{
public:
    virtual void printM()
    {
        cout << "越位溢出" << endl;
    }
};

void func(int a, int b)
{
    //throw SonNULL
    //throw SonOut();
    if (a == 0)
    {
        throw SonNULL();
    }

    if (b == 0)
    {
        throw SonOut();
    }
}

void test()
{
    int a = 10;
    int b = 0;
    try 
    {
        func(a, b);
    }
    catch (Father &f) {//3.父类引用指向子类对象
        f.printM();
    }
}

int main()
{
    test();
    return 0;
}