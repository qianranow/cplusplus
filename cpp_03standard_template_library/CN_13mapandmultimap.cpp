//
// Created by qianranow on 2022/2/25.
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

//map是关联式容器，容器自身有规则，通过键值排序，map容器中的元素是对组
//map容器和multimap容器的区别是multiset允许有相同的元素
//对组的第一个元素是键值，不能改变，第二个元素是实值，可以改变
//数据结构：红黑树，一种平衡二叉树
//迭代器：双向迭代器

void test()
{
    map<int, string>::iterator it;
    it++;
    it--;
    //it + 1;err
    //双向迭代器
}

/*
 插入数据元素操作
 map.insert(...); //往容器插入元素，返回pair<iterator,bool>
 map<int, string> mapStu;
 // 第一种 通过pair的方式插入对象
 mapStu.insert(pair<int, string>(3, "小张"));
 // 第二种 通过pair的方式插入对象
 mapStu.inset(make_pair(-1, "校长"));
 // 第三种 通过value_type的方式插入对象
 mapStu.insert(map<int, string>::value_type(1, "小李"));
 // 第四种 通过数组的方式插入值
 mapStu[3] = "小刘";
 mapStu[5] = "小王";
 */

template<class T>
void printMap(T &m)
{
    for (map<int, string>::iterator it = m.begin();it!=m.end();++it)
    {
        cout << "key:" << it->first << "value:" << it->second << endl;
    }
}


void test01()
{
    map<int, string> mymap;
    mymap.insert(pair<int, string>(3, "aaa"));
    mymap.insert(make_pair(6, "bbb"));
    mymap.insert(map<int, string>::value_type(2, "ccc"));
    mymap[4] = "ddd";

    printMap(mymap);
}

//改变规则
struct mapFunc
{
    bool operator()(const int& key1, const int& key2) const
    {
        return key1 > key2;
    }
};

void test02()
{
    map<int, string, mapFunc> m;
    m.insert(pair<int, string>(3, "aaa"));
    m.insert(make_pair(6, "bbb"));
    m.insert(map<int, string>::value_type(2, "ccc"));
    m[4] = "ddd";

    printMap(m);
}

//注意：[]方式插入数据，如果没有实值，那么键值也是存在的
void test03()
{
    map<int, string> mymap;
    mymap.insert(pair<int, string>(3, "aaa"));
    mymap.insert(make_pair(6, "bbb"));
    mymap.insert(map<int, string>::value_type(2, "ccc"));
    mymap[4] = "ddd";

    printMap(mymap);
    cout << "size:" << mymap.size() << endl;
    cout << mymap[100] << endl;//插入键值，返回的是实值
    cout << "size:" << mymap.size() << endl;
}

/*
 查找操作
 find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
 count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
 lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
 upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
 equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
 */
void test04()
{
    map<int, string> mymap;
    mymap[1] = "aaa";
    mymap[2] = "bbb";
    mymap[3] = "ccc";
    mymap[4] = "ddd";
    mymap[5] = "eee";

    map<int, string>::iterator it = mymap.find(2);
    if (it==mymap.end())
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "key:" << it->first << "value:" << it->second << endl;
    }
    //查找大于或者等于3的最小的数
    it = mymap.lower_bound(3);
    if (it==mymap.end())
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "key:" << it->first << "value:" << it->second << endl;
    }
    //查找大于3的最小的数
    it = mymap.upper_bound(3);
    if (it==mymap.end())
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "key:" << it->first << "value:" << it->second << endl;
    }

    cout << "----------------------" << endl;

    //返回大于或者等于3的两个最小的数，如果有3那么就返回3和大于3的最小数
    pair<map<int, string>::iterator, map<int, string>::iterator> ret = mymap.equal_range(3);
    if (ret.first != mymap.end())
    {
        cout << "key:" << ret.first->first << "value:" << ret.first->second << endl;
    }
    if (ret.second != mymap.end())
    {
        cout << "key:" << ret.second->first << "value:" << ret.second->second << endl;
    }
}

int main()
{
    test04();
    return 0;
}