//
// Created by qianranow on 2022/2/11.
//

#include <iostream>
using namespace std;

class Maker
{
public:
    Maker()
    {
        a = 0;
    }
    void setA(int val)
    {
        a = val;
    }
    //没有返回值，也没有void
    operator bool ()
    {
        if (a <= 0)
        {
            return false;
        }
        return true;
    }
    bool operator!()
    {
        if (a <= 0)
        {
            return true;
        }
        return false;
    }
    operator int()
    {
        return 10;
    }
public:
    int a;
};
void test()
{
    Maker m;
    m.setA(10);
    if (!m)
    {
        cout << "真" << endl;
    }
    else
    {
        cout << "假" << endl;
    }
    int b = (int)m;
    cout << b << endl;
}

int main()
{
    test();
    return 0;
}