//
// Created by qianranow on 2022/2/11.
//

#include <iostream>
using namespace std;

//继承的作用 1.代码复用 2.扩展类的功能
class Father
{
public:
    void func1()
    {
        cout << "约小姐姐" << endl;
    }
    void func2()
    {
        cout << "有钱" << endl;
    }
};

class Son : public Father
{
public:
    void func3()
    {
        cout << "有才" << endl;
    }
};

void test()
{
    Son s;
    s.func1();
    s.func2();
    s.func3();
}

int main()
{
    test();
    return 0;
}