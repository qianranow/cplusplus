//
// Created by qianranow on 2022/2/25.
//

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

//函数对象：类中重载了()，这个类实例化的对象叫函数对象（仿函数）
//一元仿函数是operator()中只需要一个参数，二元仿函数是operator()中只需要两个参数
//作用：作为算法的策略

void test()
{
    vector<int> v;
    v.push_back(8);
    v.push_back(1);
    v.push_back(6);
    v.push_back(3);
    v.push_back(7);

    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), [](int val){cout << val << " ";});
    //[](int val){cout << val << " ";}//匿名函数
}

//函数对象和普通函数的区别
//1.函数对象可以有自己的状态
//2.普通函数没有类型，函数对象有类型
//3.函数对象比普通函数执行效率有可能更高（成员函数自动申请为内联函数）
void func()
{

}

struct Myfunc//函数对象有类型
{
public:
    Myfunc()
    {
        n = 0;
    }
    void operator()()//函数对象有自己的状态
    {
        cout << "hello" << endl;
    }
public:
    int n;
};

//谓词
//1.普通函数或者重载的operator()返回值是bool类型的函数对象（仿函数）
//2.谓词可以作为一个判断式
//3.如果operator接受一个参数，那么叫做一元谓词,如果接受两个参数，那么叫做二元谓词

//內建函数对象
//1.使用內建的函数对象要加入头文件#include <functional>

void test01()
{
    plus<int> myplus;
    cout << myplus(10, 20) << endl;
}
int main()
{
    test01();
    return 0;
}