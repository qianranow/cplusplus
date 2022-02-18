//
// Created by qianranow on 2022/1/28.
//

#include "CN_28Circle.h"
#include <iostream>
using namespace std;

void G_isPointAndCircle(Circle &c, Point &p)
{
    // 获取圆心和点之间的距离
    double distance = pow((p.getX()-c.getHear().getX()), 2)+pow((p.getY()-c.getHear().getY()), 2);

    // 半径平方
    double tmpR = pow(c.getR(), 2);

    if (distance > tmpR)
    {
        cout << "全局点在圆外" << endl;
    }
    else if (distance == tmpR)
    {
        cout << "全局点在圆上" << endl;
    }
    else
    {
        cout << "全局点在圆内" << endl;
    }

}
int main()
{
    Point p;
    p.setX(10);
    p.setY(10);

    Circle c;
    c.SetHear(10, 20);
    c.SetR(20);
    c.isPointAndCircle(p);

    G_isPointAndCircle(c, p);
    return 0;
}