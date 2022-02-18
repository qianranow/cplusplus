//
// Created by qianranow on 2022/2/17.
//

#include <iostream>
#include <string>
using namespace std;

//1.创建动物的基类
class Animal
{
public:
    virtual void speak() = 0;
};

//2.创建动物
class Dog : public Animal
{
public:
    Dog(string name)
    {
        this->name = name;
    }
    virtual void speak()
    {
        cout << "小狗" << name << "汪汪汪" << endl;
    }

private:
    string name;
};

class Duck : public Animal
{
public:
    Duck(string name, string type)
    {
        this->name = name;
        this->type = type;
    }
    virtual void speak()
    {
        cout << type << "品牌的" << "小鸭" << name << "嘎嘎嘎" << endl;
    }

private:
    string name;
    string type;
};

class Tiger : public Animal
{
public:
    Tiger(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    virtual void speak()
    {
        cout << age << "岁" << "老虎" << name << "嗷嗷嗷" << endl;
    }

private:
    string name;
    int age;
};

//3.创建动物园
class Zoo
{
public:
    Zoo()
    {
        mCapacity = 1024;
        mSize = 0;
        //申请空间，存储Animal*的空间，指针数组
        this->p = new Animal*[mCapacity];
    }

    //增加动物
    int AddAnimal(Animal *animal)
    {
        if (mCapacity == mSize)
        {
            return -1;
        }
        this->p[mSize] = animal;
        mSize++;
        return 0;
    }
    void StartSpeak()
    {
        for (int i = 0; i < mSize; ++i) {
            p[i]->speak();
        }
    }
    ~Zoo()
    {
        //先释放指针数组中指针指向的堆区空间
        for (int i = 0; i < mSize; ++i) {
            if (p[i] != NULL)
            {
                delete p[i];
                p[i] = NULL;
            }
        }
        //释放指针数组
        delete[] p;
        p = NULL;
    }

private:
    Animal* *p;
    int mCapacity;
    int mSize;
};

class Cat : public Animal
{
public:
    Cat(string name)
    {
        this->name = name;
    }
    virtual void speak()
    {
        cout << "小猫" << name << "喵喵喵" << endl;
    }

private:
    string name;
};

void test()
{
    //创建动物园
    Zoo *zoo = new Zoo;

    //添加动物
    zoo->AddAnimal(new Dog("吾语"));
    zoo->AddAnimal(new Duck("黑鸭", "周黑鸭"));
    zoo->AddAnimal(new Tiger("三胖", 35));

    zoo->AddAnimal(new Cat("小蓝"));
    zoo->StartSpeak();

    //烧了动物园
    delete zoo;
}

int main()
{
    test();
    return 0;
}