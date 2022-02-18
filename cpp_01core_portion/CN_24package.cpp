//
// Created by qianranow on 2022/1/28.
//

#include <iostream>
#include <string>
using namespace std;

//封装：1.把属性和方法放到类中
class Maker
{
public:
    void set(string Name, int Id)
    {
        id = Id;
        name = Name;
    }
    void printMaker()
    {
        cout << "id=" << id << "\nname=" << name << endl;
    }

    void get()
    {
        cout << "Maker a=" << a << endl;
    }

private:
    int id;
    string name;

protected:
    int a;
};

class Son :public Maker
{
public:

    void func()
    {
        //下面这个a是从父类复制过来的
        a = 20;
    }
    void getS()
    {
        cout << "Son a=" << a << endl;
    }
};
//类外不能访问私有权限的成员
//类外可以访问公有权限的成员
//类外不能访问保护权限的成员
//子类的类内可以访问父类的保护权限的成员
//类内是没有权限之分
void test()
{
    Maker m;
    m.set("小花",1);
    m.printMaker();
}

void test01()
{
    Maker m;
    Son s;
    s.func();
    m.get();
    s.getS();
}

int main()
{
    test01();
    return 0;
}