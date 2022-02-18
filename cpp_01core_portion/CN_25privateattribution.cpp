//
// Created by qianranow on 2022/1/28.
//

#include <iostream>
#include <string>
using namespace std;

class Maker
{
public:
    void setName(string Name)
    {
        name = Name;
    }
    string getName()
    {
        return name;
    }
    void setAge(int Age)
    {
        if (Age > 0 && Age < 120)
        {
            age = Age;
        }
    }
    int getId()
    {
        return id;
    }

private:
    string name;
    int age;
    int id;
};

int main()
{
    Maker m;
    m.getId();
    return 0;
}