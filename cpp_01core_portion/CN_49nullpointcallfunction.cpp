//
// Created by qianranow on 2022/2/8.
//

#include <iostream>
using namespace std;

class Maker
{
public:
    Maker()
    {
        a = 20;
    }
    void printMaker()
    {
        if (this == NULL)
        {
            cout << "this==NULL" << endl;
            return;
        }
        cout << a << endl;
    }
private:
    int a;
};

void test()
{
    Maker *m = NULL;
    m->printMaker();
}

int main()
{
    test();
    return 0;
}