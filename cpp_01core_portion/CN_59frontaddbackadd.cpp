//
// Created by qianranow on 2022/2/10.
//

#include <iostream>
using namespace std;

void test()
{
    int a = 1;
    cout << ++a << endl;
    cout << a++ << endl;
    cout << a << endl;
}

class Maker
{
    friend ostream &operator<<(ostream &out, Maker m);
public:
    Maker(int a)
    {
        this->a = a;
    }
//    Maker(const Maker &m)
//    {
//        cout << "拷贝构造函数" << endl;
//    }
    //重载前置加加
    Maker &operator++()
    {
        ++a;
        return *this;
    }
    //重载后置加加
    Maker operator++(int)//占位参数，必须是int
    {
        //后置加加，先返回，后加加
        Maker tmp(*this);//1.*this里面的值a是等于2
        ++this->a;
        return tmp;
    }
private:
    int a;
};

ostream &operator<<(ostream &out, Maker m)
{
    cout << m.a << endl;
    return out;
}

void test02()
{
    Maker m1(1);
    cout << m1 << endl;//1
    cout << ++m1 << endl;//2
    cout << m1++ << endl;//2 这里返回的是拷贝的tmp对象
    cout << m1 << endl;//3 这里返回的是++this->a的对象
    //同等条件下，优先使用前置加加，不需要产生新的对象和调用拷贝构造
}

int main() {
    test02();
//    Maker m1(1);
//    Maker &m2 = m1;//Maker *const m2 = &m1;
//    Maker m3 = m2;
    return 0;
}