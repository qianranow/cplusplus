//
// Created by qianranow on 2022/2/25.
//

#include <iostream>
#include <vector>
using namespace std;

class Maker
{
public:
    Maker(int age)
    {
        this->age = age;
    }
    Maker(const Maker&m)
    {
        cout << "拷贝构造" << endl;
    }
public:
    int age;
};

void test()
{
    vector<Maker> v;
    Maker m(10);
    //1.把对象放入容器，其实是拷贝一份对象到容器
    //2.注意拷贝构造要能被调用
    //3.注意浅拷贝问题
    v.push_back(m);
}

int main()
{
    test();
    return 0;
}