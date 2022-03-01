//
// Created by qianranow on 2022/2/25.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

//stack
//数据结构：连续的存储空间，只有一个出口，先进后出特性
//迭代器：没有迭代器

void test01()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << "size:" << s.size() << endl;
}

class Maker
{
public:
    Maker(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
public:
    string name;
    int age;
};

void test02()
{
    stack<Maker> s;
    s.push(Maker("aaa", 18));
    s.push(Maker("bbb", 19));
    s.push(Maker("ccc", 20));

    while (!s.empty())
    {
        cout << "name:" << s.top().name << "age:" << s.top().age << endl;
        s.pop();
    }
}

int main()
{
    test02();
    return 0;
}