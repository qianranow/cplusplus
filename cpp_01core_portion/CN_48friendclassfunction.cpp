//
// Created by qianranow on 2022/2/8.
//

#include <iostream>
using namespace std;
#include <string>

//1.编译器知道类的声明，不知道类的结构
class Building; //声明类
class GoodGay
{
public:
    void func(Building &bud);
};
class Building
{
    friend void GoodGay::func(Building &bud);
public:
    Building()
    {
        keting = "客厅";
        woshi = "卧室";
    }

public:
    string keting;
private:
    string woshi;
};

void GoodGay::func(Building &bud)
{
    cout << "访问：" << bud.keting << endl;
    cout << "访问：" << bud.woshi << endl;
}

void test()
{
    Building bud;
    GoodGay GF;
    GF.func(bud);
}

int main()
{
    test();
    return 0;
}