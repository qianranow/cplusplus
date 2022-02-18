//
// Created by qianranow on 2022/2/17.
//

#include <iostream>
using namespace std;

class Drink
{
public:
    //煮水
    virtual void Boil() = 0;
    //冲泡
    virtual void Brew() = 0;
    //倒入杯中
    virtual void PourInCup() = 0;
    //加点辅料
    virtual void AddSon() = 0;

    //模板方法，把调用函数的顺序确定下来
    void func()
    {
        Boil();
        Brew();
        PourInCup();
        AddSon();
    }
};

class Coffe : public Drink
{
public:
    virtual void Boil()
    {
        cout << "煮点露水" << endl;
    }
    virtual void Brew()
    {
        cout << "拿铁" << endl;
    }
    virtual void PourInCup()
    {
        cout << "倒入盆中" << endl;
    }
    virtual void AddSon()
    {
        cout << "加点🍓" << endl;
    }
};

class Tea : public Drink
{
public:
    virtual void Boil()
    {
        cout << "煮点自来水" << endl;
    }
    virtual void Brew()
    {
        cout << "铁观音" << endl;
    }
    virtual void PourInCup()
    {
        cout << "倒入碗中" << endl;
    }
    virtual void AddSon()
    {
        cout << "加点苹果" << endl;
    }
};

void test()
{
    Drink *dr = NULL;
    dr = new Coffe;
    dr->func();
    delete dr;

    dr = new Tea;
    dr->func();
    delete dr;
}

int main()
{
    test();
    return 0;
}