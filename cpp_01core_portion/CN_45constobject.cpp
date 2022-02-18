//
// Created by qianranow on 2022/2/8.
//

#include <iostream>
using namespace std;

class Maker
{
public:
    Maker(int id, int age)
    {
        this->id = id;
        this->age = age;
        score = 100;
    }
    void printMaker()const
    {
        score = 200;
        cout << "score=" << score << endl;
    }
    void func()
    {
        cout << "func" << endl;
    }

public:
    int id;
    int age;
    mutable int score;
};

void test()
{
    //1.在数据类型前面加上const，让对象成为常对象
   const Maker m(1, 18);//常对象
   //m.id = 100;//常对象不能改变普通成员变量的值
   //m.func();//常对象不能调用普通成员函数
   m.printMaker();//常对象可以调用常函数
   m.score = 500;//常对象可以修改mutable修饰的成员变量
   Maker m2(2, 20);
   m2.printMaker();//普通对象也可以调用常函数
}

int main()
{
    test();
    return 0;
}