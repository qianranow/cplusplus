//
// Created by qianranow on 2022/2/28.
//

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;

//函数对象适配：当函数对象的参数不够用，那么可以用适配器来配置函数对象
//函数对象适配器：bind1st，bind2nd，将二元函数对象配置为一元函数对象

//第一步：继承binary_function<参数1, 参数2, 返回类型>
struct MyFunc : public binary_function<int, int, void>
{
    void operator() (int v1, int v2) const //第二步：加上const成为常函数，参数变2个
    {
        cout << "v1=" << v1 << endl;
        cout << "v2=" << v2 << endl;
        cout << v1 + v2 << endl;//第三步：实现函数体
    }
};

//需求：打印时，每个元素加100然后打印出来
void test()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //for_each(v.begin(), v.end(), MyFunc());
    //第四步：用bind2nd来绑定函数对象
    for_each(v.begin(), v.end(), bind2nd(MyFunc(), 100));

}
//bind1st和bind2nd的区别
//bind1st把100绑定给第一个参数
//bind2nd把100绑定给第二个参数

//函数对象适配器：not1，not2，取反
//not1和not2的区别：not1针对一元函数对象，not2针对二元函数对象

//第一步：继承
struct MyNotFunc : public unary_function<int, bool>
{
    bool operator()(int v) const//第二步：变为常函数
    {
        return v>=20;
    }
};

void test02()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(50);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    //第三步：适配
    vector<int>::iterator it = find_if(v.begin(), v.end(), not1(MyNotFunc()));
    if (it == v.end())
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "查找成功" << *it << endl;
    }

    //not2的使用
    //less 二元函数对象
    vector<int> v2;
    v2.push_back(10);
    v2.push_back(50);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);
    sort(v2.begin(), v2.end(), not2(less<int>()));
    for_each(v2.begin(), v2.end(), [](int val){cout << val << " ";});
}

//普通函数进行适配
//第一步：把一个参数变为两个参数
void myprint(int val, int val2)
{
    cout << val + val2 << " ";
}

void test03()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    //第二步：把普通函数变为函数对象ptr_fun
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(myprint), 100));
}

//成员函数适配
//mem_fun：如果存储的是对象指针，需要使用mem_fun
//mem_fun_ref：如果存储的是对象，需要使用mem_fun_ref
class Maker
{
public:
    Maker(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    //成员函数
    void MyPrintMaker()
    {
        cout << "name:" << this->name << "age:" << this->age << endl;
    }

public:
    string name;
    int age;
};

//void myprintmaker(Maker m)
//{
//    cout << "name:" << m.name << "age:" << m.age << endl;
//}

void test04()
{
    vector<Maker> v;
    v.push_back(Maker("aaa", 10));
    v.push_back(Maker("bbb", 20));
    v.push_back(Maker("ccc", 30));
    //当容器存储的是对象，用mem_fun_ref适配他的成员函数
    for_each(v.begin(), v.end(), mem_fun_ref(&Maker::MyPrintMaker));

    cout << "------------------" << endl;

    vector<Maker*> vp;
    vp.push_back(new Maker("aaa", 10));
    vp.push_back(new Maker("bbb", 20));
    vp.push_back(new Maker("ccc", 30));
    //当容器存储的是对象指针，用mem_fun适配他的成员函数
    for_each(vp.begin(), vp.end(), mem_fun(&Maker::MyPrintMaker));
}

int main()
{
    test04();
    return 0;
}