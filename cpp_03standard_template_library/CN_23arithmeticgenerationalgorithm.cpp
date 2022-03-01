//
// Created by qianranow on 2022/3/1.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

//accumulate：计算容器元素累计总和
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    //第三个参数是在总和上再加上0
    int ret = accumulate(v.begin(), v.end(), 0);
    cout << ret << endl;
}

class Maker
{
public:
    Maker(int age)
    {
        this->age = age;
    }
public:
    int age;
};

struct MyPuls
{
    int operator()(int val, Maker &m)
    {
        return val + m.age;
    }
};

void test02()
{
    vector<Maker> v;
    v.push_back(Maker(10));
    v.push_back(Maker(20));
    v.push_back(Maker(30));

    int ret = accumulate(v.begin(), v.end(), 0, MyPuls());
    cout << ret << endl;

}

//fill：向容器中添加元素
void test03()
{
    vector<int> v;
    //要开辟空间
    v.resize(10);
    fill(v.begin(), v.end(), 100);

    for_each(v.begin(), v.end(), [](int val){cout << val << " ";});
    cout << endl;
}

int main()
{
    test03();
    return 0;
}