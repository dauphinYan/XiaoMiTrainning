#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    Point(int x, int y):x(x),y(y){}

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
private:
    Point pointld;
    Point pointru;

public:
    Rectangle(Point ld, Point ru):pointld(ld),pointru(ru){}

    void calculator()
    {
        int area;
        area = (pointru.getY() - pointld.getY()) * (pointru.getX() - pointld.getX());
        cout << "面积为："<<area << endl;
        cout << "顶点为：" << endl;
        cout << "LD(" << pointld.getX() << ", " << pointld.getY() << ")" << endl;
        cout << "LU(" << pointld.getX() << ", " << pointru.getY() << ")" << endl;
        cout << "RU(" << pointru.getX() << ", " << pointru.getY() << ")" << endl;
        cout << "RD(" << pointru.getX() << ", " << pointld.getY() << ")" << endl;
        
    }
};

int main()
{
    Point pointld(0, 0);
    Point pointru(1, 1);

    Rectangle re(pointld, pointru);
    re.calculator();
    return 0;
}