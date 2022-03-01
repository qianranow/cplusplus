//
// Created by qianranow on 2022/2/25.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;

//queue
//数据结构：连续的存储空间，有两个口，一个是进数据，一个是出数据，有先进先出的特性
//迭代器：没有迭代器

void test01()
{
    queue<int> q;
    for (int i = 0; i < 5; ++i) {
        {
            q.push(i+1);
        }

    }
    cout << "front:" << q.front() << endl;
    cout << "back:" << q.back() << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << q.size() << endl;
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
    queue<Maker *> q;
    q.push(new Maker("aaa", 18));
    q.push(new Maker("bbb", 19));
    q.push(new Maker("ccc", 20));

    while (!q.empty())
    {
        Maker *m = q.front();
        cout << m->name << " " << m->age << endl;
        q.pop();
        delete m;
    }

}

int main()
{
    test02();
    return 0;
}