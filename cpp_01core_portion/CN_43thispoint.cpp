//
// Created by qianranow on 2022/2/8.
//

#include <iostream>
using namespace std;

class Maker
{
public:
    Maker()
    {
        a = 10;
        b = 20;
    }
    //1.每个对象都有一个隐藏的this指针，但不属于对象，是编译器添加的
    //2.编译器会把this指针传入成员函数内
    //3.this指针指向对象的存储空间
    void func()//func函数只有一份
    {
        cout << this->a << " " << this->b << endl;
    }
public:
    int a;
    int b;
};

void test01()
{
    //1.分配空间，2.调用构造函数
    Maker m;
    m.func();
    Maker m2;
    m2.func();
}

class Maker2
{
public:
    //1.当形参名和成员变量名相同时，用this指针区分
    Maker2(int id)
    {
        this->id = id;
    }
    //2.返回对象的本身
    Maker2 &getMaker2()
    {
        return *this;//运算符重载时有用
    }
    static void func()
    {
        //3.this指针的指向不能改变，也就是说this是Maker *const this;
        //this->a; err
    }
public:
    int id;
    static int a;
};
int Maker2::a = 200;
void test02()
{

}

int main()
{
    test01();
    return 0;
}