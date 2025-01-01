#include <iostream>

using namespace std;
class Point {
int x;
int y;
public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    Point(int x)
    {
        this->x = this->y = x;
    }
    Point()
    {
        this->x = this->y = -1;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

};
class Rectangle
{
    Point *p1, *p2;
    int width, height;
public:
    Rectangle(Point *pt1, Point *pt2)
    {
        p1 = pt1;
        p2 = pt2;
        if (p1 && p2)
        {
            width = abs(p1->getY() - p2->getY());
            height = abs(p1->getX() - p2->getX());
        }
    }
    Rectangle()
    {
        p1 = p2 = NULL;
    }
    void setP1(Point * p)
    {
        p1 = p;
        if (p1 && p2)
        {
            width = abs(p1->getY() - p2->getY());
            height = abs(p1->getX() - p2->getX());
        }
        else width = height = 0;
    }
    void setP2(Point * p)
    {
        p2 = p;
        if (p1 && p2)
        {
            width = abs(p1->getY() - p2->getY());
            height = abs(p1->getX() - p2->getX());
        }
        else width = height = 0;
    }
    Point * getP1()
    {
        return p1;
    }
    Point * getP2()
    {
        return p2;
    }
    int area()
    {
        return width * height;
    }

};
int main()
{
    Point p1(7), p2(4, 9);
    Rectangle r(&p1, &p2);
    cout<<"reactangle area is "<<r.area()<<endl;
}
