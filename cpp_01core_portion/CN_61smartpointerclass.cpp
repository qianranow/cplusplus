//
// Created by qianranow on 2022/2/11.
//

#include <iostream>
using namespace std;

//智能指针类是管理另一个类的对象的释放
class Maker
{
public:
    Maker()
    {
        cout << "无参构造" << endl;
    }
    ~Maker()
    {
        cout << "析构函数" << endl;
    }
    void printMaker()
    {
        cout << "hello Maker" << endl;
    }
};

class SmartPoint
{
public:
    SmartPoint(Maker *m)
    {
        this->pMaker = m;
    }
    ~SmartPoint()
    {
        if (this->pMaker != NULL)
        {
            cout << "SmartPoint 析构函数" << endl;
            delete this->pMaker;
            this->pMaker = NULL;
        }
    }
    //重载指针运算符
    Maker *operator->()
    {
        return this->pMaker;
    }
    //重载星花
    Maker &operator*()
    {
        return *pMaker;
    }
private:
    Maker *pMaker;
};

void test01()
{
    Maker *p = new Maker;
    SmartPoint sm(p);//栈区，会调用析构函数
    //当test01()函数结束时，会调用SmartPoint的析构函数
    //在这析构函数中delete了Maker的对象，会调用Maker的析构函数
}

void test02()
{
    Maker *p = new Maker;
    SmartPoint sm(p);
    //sm-> == pMaker->
    sm->printMaker();
    (*sm).printMaker();
}

int main()
{
    test02();
    return 0;
}