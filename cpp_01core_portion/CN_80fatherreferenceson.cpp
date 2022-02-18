//
// Created by qianranow on 2022/2/17.
//

#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal speak()" << endl;
    }
};

class Dog : public Animal
{
public:
    virtual void speak()
    {
        cout << "Dog speak()" << endl;
    }
};

void test()
{
    Animal *dog = new Dog();
    Animal* &an = dog;
    an->speak();
    delete dog;
}

int main()
{
    test();
    return 0;
}