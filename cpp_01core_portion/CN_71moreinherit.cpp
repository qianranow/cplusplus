//
// Created by qianranow on 2022/2/11.
//

#include <iostream>
using namespace std;

class Father1
{
public:
    int bmw;
};

class Father2
{
public:
    int bmw;
};

//1.多继承是一个类有两个以上的父类
//2.多继承的问题是，当父类中有同名成员时，子类中会产生二义性问题
class Son : public Father1, public Father2
{

};

void test()
{
    Son s;
    //s.bmw; //err有二义性问题
}

int main()
{
    return 0;
}