//
// Created by qianranow on 2022/2/17.
//

#include <iostream>
#include <string>
using namespace std;

class Manito
{
public:
    virtual void show() = 0;

};

class Maker : public Manito
{
public:
    Maker(string name, int age, string sex, string skill)
    {
        this->name = name;
        this->age = age;
        this->sex = sex;
        this->skill = skill;
    }
    virtual void show()
    {
        cout << name << "展现" << skill << endl;
    }
private:
    string name;
    int age;
    string sex;
    string skill;
};

//班级
class MyClass
{
public:
    MyClass()
    {
        mCapacity = 50;
        mSize = 0;
        this->p = new Manito*[mCapacity];
    }

    //增加人员
    void AddManito(Manito *ma)
    {
        if (mSize == mCapacity) return;
        this->p[mSize] = ma;
        mSize++;
    }

    //秀技能
    void StartShow()
    {
        for (int i = 0; i < mSize; ++i) {
            p[i]->show();
        }
    }

    ~MyClass()
    {
        for (int i = 0; i < mSize; ++i) {
            if (p[i] != NULL)
            {
                delete p[i];
                p[i] = NULL;
            }
        }
        delete[] p;
        p = NULL;
    }
private:
    Manito* *p;
    int mCapacity;
    int mSize;
};

void test()
{
    MyClass *my = new MyClass;
    my->AddManito(new Maker("Maker", 18, "男", "跳舞"));
    my->StartShow();
    delete my;
}

int main()
{
    test();
    return 0;
}