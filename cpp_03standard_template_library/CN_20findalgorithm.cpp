//
// Created by qianranow on 2022/2/28.
//

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;


//find：查找元素
//find(开始迭代器, 结束迭代器, 要查找的数值)
//find_if(开始迭代器, 结束迭代器, 谓词或函数对象)

//adjacent_find：查找相邻重复元素
//adjacent_find(开始迭代器, 结束迭代器)
//adjacent_find(开始迭代器, 结束迭代器, 谓词或函数对象)

//binary_search：二分查找法，数据必须要有序，返回值是bool
//binary_search(开始迭代器, 结束迭代器, 数值)
//binary_search(开始迭代器, 结束迭代器, 对象, 函数对象)
//注意：存储对象时，需要重载<或>

//count：统计元素个数
//count(开始迭代器, 结束迭代器, 数值)
//count(开始迭代器, 结束迭代器, 谓词或函数对象)

bool MyPrint(int v)
{
    return v > 30;
}
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    vector<int>::iterator it = find(v.begin(), v.end(), 20);
    if (it == v.end())
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "查找成功=" << *it << endl;
    }

    it = find_if(v.begin(), v.end(), MyPrint);
    if (it == v.end())
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "查找成功=" << *it << endl;
    }

}

class Maker
{
public:
    Maker(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    //重载==
    bool operator==(const Maker& m)
    {
        return this->name == m.name && this->age == m.age;
    }

public:
    string name;
    int age;
};

struct MyFind : public binary_function<Maker, Maker, bool>
{
    bool operator()(Maker m, Maker m2) const
    {
        return m.name == m2.name && m.age == m2.age;
    }
};

void test02()
{
    vector<Maker> v;
    v.push_back(Maker("aaa", 18));
    v.push_back(Maker("bbb", 19));
    v.push_back(Maker("ccc", 20));
    v.push_back(Maker("ddd", 21));
    v.push_back(Maker("eee", 22));

    vector<Maker>::iterator it = find(v.begin(), v.end(), Maker("aaa", 18));
    if (it == v.end())
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "查找成功:" << "name:" << it->name << ";age:" << it->age << endl;
    }

    it = find_if(v.begin(), v.end(), bind2nd(MyFind(), Maker("ccc", 20)));
    if (it == v.end())
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "查找成功:" << "name:" << it->name << ";age:" << it->age << endl;
    }
}


class Maker2
{
public:
    Maker2(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

public:
    string name;
    int age;
};

 bool myadjacent_find(Maker2 &m1, Maker2 &m2)
 {
     return m1.name == m2.name && m1.age == m2.age;
 }

//adjacent_find：查找相邻重复元素
void test03()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it == v.end())
    {
        cout << "查找相邻的重复元素失败" << endl;
    }
    else
    {
        cout << "查找成功:" << *it << endl;
    }

    vector<Maker2> v2;
    v2.push_back(Maker2("aaa1", 10));
    v2.push_back(Maker2("aaa2", 20));
    v2.push_back(Maker2("aaa4", 40));
    v2.push_back(Maker2("aaa4", 40));
    v2.push_back(Maker2("aaa5", 50));

    vector<Maker2>::iterator it2 = adjacent_find(v2.begin(), v2.end(), myadjacent_find);
    if (it2 == v2.end())
    {
        cout << "查找相邻的重复元素失败" << endl;
    }
    else
    {
        cout << "查找成功:" << it2->name << " " << it2->age << endl;
    }
}

//binary_search：二分查找
//注意：在无序序列中不可用
class Student
{
public:
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    bool operator>(const Student &stu) const
    {
        return this->age > stu.age;
    }
    //less
    bool operator<(const Student &stu) const
    {
        return this->age < stu.age;
    }
public:
    string name;
    int age;
};
void test04()
{
     vector<int> v;
     v.push_back(10);
     v.push_back(20);
     v.push_back(30);
     v.push_back(40);
     v.push_back(50);
     v.push_back(60);

     bool flg = binary_search(v.begin(), v.end(), 30);
     if (flg)
     {
         cout << "找到" << endl;
     }
     else
     {
         cout << "没有找到" << endl;
     }

     vector<Student> vs;
     vs.push_back(Student("a1", 5));
     vs.push_back(Student("a2", 4));
     vs.push_back(Student("a3", 3));
     vs.push_back(Student("a4", 2));
     vs.push_back(Student("a5", 1));

     //存储对象，如果使用less，那么数据要是升序，并且要重载<，greater这需要数据是降序，并且要重载>
     bool flg2 = binary_search(vs.begin(), vs.end(), Student("a4", 4), greater<Student>());
     if (flg)
     {
         cout << "找到" << endl;
     }
     else
     {
         cout << "没有找到" << endl;
     }
}

void test05()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    //查询1有多少个元素
    int n = count(v.begin(), v.end(), 1);
    cout << n << endl;
    //大于2的元素有多少个
    n = count_if(v.begin(), v.end(), [](int val)->bool{return val > 2;});
    cout << n << endl;
}

int main()
{
    test05();
    return 0;
}