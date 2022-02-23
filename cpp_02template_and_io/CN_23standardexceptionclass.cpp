//
// Created by qianranow on 2022/2/22.
//

#include <iostream>
#include <string>
using namespace std;

class MyOut_of : public exception
{
public:
    MyOut_of(const char *errorinfo)
    {
        //const char*转换string
        this->m_Info = string(errorinfo);
    }
    MyOut_of(const string errorinfo)
    {
        this->m_Info = errorinfo;
    }
    const char * what() const noexcept override
    {
        //把string转换const char*
        return this->m_Info.c_str();
    }

public:
    string m_Info;
};

class Maker
{
public:
    Maker(int age)
    {
        if (age < 0 || age > 150)
        {
            //throw out_of_range("年龄不在范围内");
            throw MyOut_of("自己的异常类，年龄不在范围内");
        }
        else
        {
            this->age = age;
        }
    }
public:
    int age;
};

void test()
{
    try
    {
        Maker m(200);
    }
    catch (out_of_range &ex)
    {
        cout << ex.what() << endl;
    }
    catch (MyOut_of &ex)
    {
        cout << ex.what() << endl;
    }
}

int main()
{
    test();
    return 0;
}