//
// Created by qianranow on 2022/2/28.
//

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

//1.for_each：遍历打印
//for_each(开始迭代器, 结束迭代器, 函数对象)

//2.transform：搬运
//transform(源开始迭代器, 源结束迭代器, 目标开始迭代器, 函数对象)
//transform(源1开始迭代器, 源1结束迭代器, 源2开始迭代器, 目标开始迭代器, 函数对象)

struct myPrint
{
public:
    myPrint()
    {
        a = 0;
    }
    void operator()(const int &val)
    {
        cout << val << " ";
        a++;
    }
public:
    int a;
};

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    myPrint m;
    myPrint m2 = for_each(v.begin(), v.end(), myPrint());
    cout << endl;
    cout << m2.a << endl;
    cout << m.a << endl;

}

//transform算法：将指定容器区间元素搬到另一容器中
//注意：transform不会给目标容器分配内存，所以需要我们提前分配好内存
struct MyAdd
{
    int operator()(int v1)
    {
        return v1 + 100;
    }
};
void test02()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int> v2;
    //要手动分配空间
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), MyAdd());
    for_each(v2.begin(), v2.end(), [](int val){cout << val << " ";});
}

//把两个容器中的元素处理后放入第三个容器中
struct MyAdd2
{
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};
void test03()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int> v2;
    v2.push_back(100);
    v2.push_back(200);
    v2.push_back(300);
    v2.push_back(400);
    v2.push_back(500);

    vector<int> v3;
    v3.resize(v2.size());
    transform(v.begin(), v.end(), v2.begin(), v3.begin(), MyAdd2());
    for_each(v3.begin(), v3.end(), [](int val){cout << val << " ";});
}

int main()
{
    test03();
    return 0;
}