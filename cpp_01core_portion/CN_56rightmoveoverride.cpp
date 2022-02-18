//
// Created by qianranow on 2022/2/10.
//

#include <iostream>
#include <string>
using namespace std;

void test()
{
    int a;
    cin >> a;
    cout << a << endl;
}

class Maker
{
    friend istream &operator>>(istream &in, Maker &m);
public:
    Maker(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    int getAge()
    {
        return age;
    }
private:
    string name;
    int age;
};

istream &operator>>(istream &in, Maker &m)
{
    in>>m.age;
    in>>m.name;
    return in;
}

void test02()
{
    Maker m("悟空", 15);
    Maker m2("悟空2", 25);
    cin >> m >> m2;
    cout << m.getAge() << endl;
    cout << m2.getAge() << endl;
}

int main()
{
    test02();
    return 0;
}