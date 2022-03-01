//
// Created by qianranow on 2022/3/1.
//

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

//copy
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    vector<int> v2;
    v2.resize(v.size());
    copy(v.begin(), v.end(), v2.begin());
    for_each(v2.begin(), v2.end(), [](int val){cout << val << " ";});
    cout << endl;
}

//replace：将容器内指定范围的旧元素修改为新元素
//replace_if：将容器内指定范围满足条件的元素替换为新元素
bool myfunc(int val)
{
    return val > 30;
}

void test02()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    for_each(v.begin(), v.end(), [](int val){cout << val << " ";});
    cout << endl;

    replace(v.begin(), v.end(), 20, 200);
    for_each(v.begin(), v.end(), [](int val){cout << val << " ";});
    cout << endl;

    replace_if(v.begin(), v.end(), myfunc, 300);
    for_each(v.begin(), v.end(), [](int val){cout << val << " ";});
    cout << endl;
}

//swap
void test03()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vector<int> v2;
    v2.push_back(100);
    v2.push_back(200);
    v2.push_back(300);

    swap(v1, v2);
    for_each(v1.begin(), v1.end(), [](int val){cout << val << " ";});
    cout << endl;
    for_each(v2.begin(), v2.end(), [](int val){cout << val << " ";});
    cout << endl;
}

int main()
{
    test03();
    return 0;
}