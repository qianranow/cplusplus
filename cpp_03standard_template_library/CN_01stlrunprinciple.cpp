//
// Created by qianranow on 2022/2/23.
//

#include <iostream>
using namespace std;

//数组容器
template<class T>
class MyArray
{
public:
    //保护原生指针，给原生指针取别名
    typedef T* iterator;
    MyArray()
    {
        mCacpacity = 10;
        mSize = 10;
        p = new T[mCacpacity];
        for (int i = 0; i <mCacpacity ; ++i) {
            p[i] = i + 1;
        }
    }

    //提供迭代器，开始位置的迭代器
    T* begin()
    {
        return p;
    }

    //返回结束位置的迭代器
    T *end()
    {
        return p + mSize;
    }
    
public:
    T *p;
    int mCacpacity;
    int mSize;
};

//算法
template<class T>
void printMyArray(T begin, T end)
{
    for (; begin != end; ++begin)
    {
        cout << *begin << " ";
    }
    cout << endl;
}

void test01()
{
    MyArray<int> arr;
    //获取容器提供的开始位置迭代器
    MyArray<int>::iterator begin = arr.begin();
    //获取容器提供的结束位置迭代器
    MyArray<int>::iterator end = arr.end();
    printMyArray(begin, end);
}

int main()
{
    test01();
    return 0;
}