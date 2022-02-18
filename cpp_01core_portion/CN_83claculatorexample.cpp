//
// Created by qianranow on 2022/2/18.
//

#include <iostream>
using namespace std;

class rule
{
public:
    virtual double getNum(double a, double b) = 0;
    virtual ~rule() = 0;
};

rule::~rule()
{
    cout << "rule free" << endl;
}

class rule_add : public rule
{
public:
    virtual double getNum(double a, double b)
    {
        return a + b;
    }
};

class rule_minus : public rule
{
public:
    virtual double getNum(double a, double b)
    {
        return a - b;
    }
};

class rule_take : public rule
{
public:
    virtual double getNum(double a, double b)
    {
        return a * b;
    }
};

class rule_division : public rule
{
public:
    virtual double getNum(double a, double b)
    {
        if (b == 0)
        {
            cout << "除数不能为0" << endl;
            return a / b;
        }
        return a / b;
    }
    ~rule_division() override
    {
        cout << "rule_division free" << endl;
    }
};

void test()
{
    rule *r = NULL;
    r = new rule_add;
    cout << r->getNum(30, 10) << endl;

    r = new rule_minus;
    cout << r->getNum(30, 10) << endl;

    r = new rule_take;
    cout << r->getNum(30, 10) << endl;

    r = new rule_division;
    cout << r->getNum(30, 10) << endl;

    delete r;
}

int main()
{
    test();
    return 0;
}