//
// Created by qianranow on 2022/1/28.
//

#include "CN_28Circle.h"

void Circle::SetR(int r)
{
    mR = r;
}
void Circle::SetHear(Point &p)
{
    mHear.setX(p.getX());
    mHear.setY(p.getY());
}
void Circle::SetHear(int x, int y)
{
    mHear.setX(x);
    mHear.setY(y);
}
int Circle::getR()
{
    return mR;
}
Point Circle::getHear()
{
    return mHear;
}
void Circle::isPointAndCircle(Point &p)
{
    // 获取圆心和点之间的距离
    double distance = pow((p.getX()-mHear.getX()), 2)+pow((p.getY()-mHear.getY()), 2);

    // 半径平方
    double tmpR = pow(mR, 2);

    if (distance > tmpR)
    {
        cout << "点在圆外" << endl;
    }
    else if (distance == tmpR)
    {
        cout << "点在圆上" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }
}