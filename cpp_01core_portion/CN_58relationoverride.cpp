//
// Created by qianranow on 2022/2/10.
//

#include <iostream>
using namespace std;

class Maker
{
public:
    Maker()
    {
        id = 0;
        age = 0;
    }
    Maker(int id, int age){
        this->id = id;
        this->age = age;
    }
    bool operator==(Maker &m)
    {
        if (this->id == m.id && this->age == m.age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
public:
    int id;
    int age;
};

void test()
{
    Maker p1(1, 20);
    Maker p2;
    if (p1 == p2)
    {
        cout << "真" << endl;
    }
    else
    {
        cout << "假" << endl;
    }
}

int main()
{
    test();
    return 0;
}