//
// Created by qianranow on 2022/1/27.
//

#include <iostream>
#include <string>
using namespace std;

class Circle
{
public:
    void setR(double r)
    {
        mR = r;
    }
    double getL()
    {
        return 2*3.14*mR;
    }
public: //公有权限
    double mR; //成员变量，成员属性
};

void test()
{
    Circle c;
    c.setR(100);
    c.getL();
    cout << "圆的周长=" << c.getL() << endl;
}

void test02()
{
    char *p = "hello";
    char buf[100] = "hello";
    cout << buf << endl;

    string str = "world";
    cout << str << endl;
}

int main()
{
    test02();
    return 0;
}