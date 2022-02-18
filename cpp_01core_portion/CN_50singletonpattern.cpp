//
// Created by qianranow on 2022/2/8.
//

#include <iostream>
using namespace std;
//单例模式是一个类只能实例化一个对象
class Maker
{
    //1.把构造函数私有化
private:
    Maker()
    {
        cout << "无参构造" << endl;
    }
    Maker(const Maker &m)
    {

    }

public:
    //静态成员函数，访问静态成员变量
    static Maker* getMaker()
    {
        return pMaker;
    }

private:
    //2.定义一个类内的静态成员指针
    static Maker *pMaker;
};
//3.在类外初始化时，new一个对象
Maker *Maker::pMaker = new Maker;

void test()
{
    // Maker m;
    Maker *m = Maker::getMaker();
    Maker *m2 = Maker::getMaker();
    cout << "m=" << m << "\nm2=" << m2 << endl;

//    Maker m3 = *m;//调用拷贝构造
//    cout << "m3=" << &m3 << endl;
}

int main()
{
    test();
    return 0;
}