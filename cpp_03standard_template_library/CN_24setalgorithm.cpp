//
// Created by qianranow on 2022/3/1.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

//set_intersection：求两个set集合的交集
//注意：两个集合必须是有序序列
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }

    vector<int> v2;
    for (int i = 5; i < 15; ++i) {
        v2.push_back(i);
    }

    vector<int> v3;
    v3.resize(min(v1.size(), v2.size()));
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), v3.end(), [](int val){cout << val << " ";});
    cout << endl;
}

//set_union：求两个set集合的并集
//注意：两个集合必须是有序序列
void test02()
{
    vector<int> v1;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }

    vector<int> v2;
    for (int i = 5; i < 15; ++i) {
        v2.push_back(i);
    }

    vector<int> v3;
    v3.resize(v1.size()+v2.size());
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), v3.end(), [](int val){cout << val << " ";});
    cout << endl;
}

//set_difference：求两个set集合的差集
//注意：两个集合必须是有序序列
void test03()
{
    vector<int> v1;
    for (int i = 1; i < 6; ++i) {
        v1.push_back(i);
    }

    vector<int> v2;
    for (int i = 2; i < 7; ++i) {
        v2.push_back(i);
    }

    vector<int> v3;
    v3.resize(min(v1.size(), v2.size()));
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), v3.end(), [](int val){cout << val << " ";});
    cout << endl;
}

int main()
{
    test03();
    return 0;
}