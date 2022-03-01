//
// Created by qianranow on 2022/2/25.
//

#include <iostream>
#include <set>//multset也是这个头文件
#include <algorithm>
#include <string>
using namespace std;

//set容器是关联式容器，容器自身有规则，通过键值排序，set容器中的元素是键值也是实值
//set容器和multiset容器的区别是multiset允许有相同的元素
//数据结构：红黑树，一种平衡二叉树
//迭代器：双向迭代器
//改变规则：默认是从小到大，改变规则，加入谓词到<>第二个参数中
//注意：set容器插入相同元素时，不会报错，但是不插入数据；set容器存储对象时，需要告诉set容器的规则

void test()
{
    set<int>::iterator it;
    it++;
    it--;
    //it + 2;err
    //双向迭代器
}

void printS(set<int> &s)
{
    for (set<int>::iterator it = s.begin();it!=s.end();++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

/*
 构造函数
 set<T> st;//set默认构造函数：
 mulitset<T> mst; //multiset默认构造函数:
 set(const set &st);//拷贝构造函数

 赋值操作
 set&operator=(const set &st);//重载等号操作符
 swap(st);//交换两个集合容器

 大小操作
 size();//返回容器中元素的数目
 empty();//判断容器是否为空

 插入和删除操作
 insert(elem);//在容器中插入元素。
 clear();//清除所有元素
 erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
 erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
 erase(elem);//删除容器中值为elem的元素。
 */
void test01()
{
    set<int> s;
    s.insert(4);
    s.insert(8);
    s.insert(2);
    s.insert(10);
    s.insert(7);
    //自身规则进行排序，从小到大
    printS(s);

}
struct myFunc
{
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
void printSet2(set<int, myFunc> &s)
{
    for (set<int, myFunc>::iterator it = s.begin(); it!=s.end();++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
//改变set容器的规则，变为降序（从大到小）
void test02()
{
    set<int, myFunc> s;
    s.insert(4);
    s.insert(8);
    s.insert(2);
    s.insert(10);
    s.insert(7);
    printSet2(s);
}
//set容器不允许有两个相同的元素
void test03()
{
    set<int, myFunc> s;
    s.insert(4);
    s.insert(8);
    s.insert(2);
    s.insert(10);
    s.insert(7);
    printSet2(s);
    //注意：set容器不允许有两个相同的元素，但是插入相同的元素，编译不会报错，运行也不报错
    //只是不把数据插入容器
    s.insert(8);
    printSet2(s);
    pair<set<int, myFunc>::iterator ,bool> ret = s.insert(11);
    if (ret.second)
    {
        cout << "插入成功" << endl;
    }
    else
    {
        cout << "插入失败" << endl;
    }
    printSet2(s);
    s.erase(2);
    s.erase(s.begin());
    printSet2(s);
}

void print(int v)
{
    cout << v << " ";
}

//不能通过算法排序
void test04()
{
    multiset<int> s;
    s.insert(4);
    s.insert(8);
    s.insert(2);
    s.insert(2);
    s.insert(10);
    s.insert(7);
    //不同通过算法排序来排序关联式容器的元素
    //sort(s.begin(), s.end());
    for_each(s.begin(), s.end(), print);
    cout << endl;
}

/*
 查找操作
 find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
	•	count(key);//查找键key的元素个数
	•	lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
	•	upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
 equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
 */
void test05()
{
    set<int> s;
    s.insert(4);
    s.insert(8);
    s.insert(6);
    s.insert(7);
    s.insert(9);

    set<int>::iterator it = s.find(10);
    if (it == s.end())
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "查找成功" << *it << endl;
    }

    //查找大于或者等于2的最小的数
    it = s.lower_bound(2);
    if (it == s.end())
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "查找成功" << *it << endl;
    }

    //查找大于2的最小的数
    it = s.upper_bound(2);
    if (it == s.end())
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "查找成功" << *it << endl;
    }
    //返回大于或者等于2的两个最小的数，如果有2那么就返回2和大于2的最小数
    pair<set<int>::iterator, set<int>::iterator> ret = s.equal_range(2);
    cout << *(ret.first) << endl;
    cout << *(ret.second) << endl;

    multiset<int> s1;
    s1.insert(4);
    s1.insert(4);
    s1.insert(4);
    s1.insert(9);
    s1.insert(7);

    cout << s1.count(4) << endl;
}

//存储对象
class Maker
{
public:
    Maker(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
public:
    string name;
    int age;
};

//存储对象时，需要告诉set容器的规则
struct Makerfunc
{
    bool operator()(const Maker &m1, const Maker &m2)
    {
        return m1.age > m2.age;
    }
};

void test06()
{
    set<Maker, Makerfunc> s;
    s.insert(Maker("aaa", 18));
    s.insert(Maker("bbb", 19));
    s.insert(Maker("ccc", 20));
    s.insert(Maker("ddd", 21));
    s.insert(Maker("eee", 22));

    for (set<Maker, Makerfunc>::iterator it = s.begin();it!=s.end();++it)
    {
        cout << "name:" << it->name << "age:" << it->age << endl;
    }
}

int main()
{
    test06();
    return 0;
}