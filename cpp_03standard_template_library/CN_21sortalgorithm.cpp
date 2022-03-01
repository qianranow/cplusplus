//
// Created by qianranow on 2022/2/28.
//

#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

//merge：容器元素合并，并存储到另一容器中
//注意：两个容器必须是有序的
void test01()
{
    vector<int> v1;
    vector<int> v2;

    for (int i = 5; i >= 0; i--) {
        v1.push_back(i+1);
        v2.push_back(i+2);
    }

    vector<int> v3;
    v3.resize(v1.size()+v2.size());
    //如果数据是升序，那么第六个参数就不用写
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), v3.end(), [](int val){cout << val << " ";});
    //如果数据是降序，那么第六个参数就要写greater<int>()
//    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), greater<int>());
//    for_each(v3.begin(), v3.end(), [](int val){cout << val << " ";});
}

//sort：容器元素排序
void test02()
{
    vector<int> v;
    v.push_back(8);
    v.push_back(12);
    v.push_back(2);
    v.push_back(7);
    v.push_back(3);
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](int val){cout << val << " ";});
    //如果元素是对象，那么要写第三个参数
    //sort(v.begin(), v.end(), 函数对象);
}

//shuffle：洗牌
void test03()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i+1);
    }
    for_each(v1.begin(), v1.end(), [](int val){cout << val << " ";});
    cout << endl;
    shuffle(v1.begin(), v1.end(), std::mt19937(std::random_device()()));
    for_each(v1.begin(), v1.end(), [](int val){cout << val << " ";});
    cout << endl;
}

//reverse：反转指定范围的元素
void test04()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i+1);
    }
    for_each(v1.begin(), v1.end(), [](int val){cout << val << " ";});
    cout << endl;
    reverse(v1.begin(), v1.end());
    for_each(v1.begin(), v1.end(), [](int val){cout << val << " ";});
    cout << endl;
}

int main()
{
    test04();
    return 0;
}