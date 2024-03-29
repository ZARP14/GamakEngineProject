#include <iostream>
#include <vector>
#include <random>

struct point
{
    point()
    {
        x = std::rand() % 100;
        y = std::rand() % 100;
    }
    int x;
    int y;
    void random()
    {
        x = std::rand() % 100;
        y = std::rand() % 100;
    }

};

bool check(std::vector<point>& v, point& p)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (p.x == v[i].x && p.y == v[i].y)
        {
            return false;
        }
    }
    return true;
}

bool way(point p0, point p1, point p2)
{
    float k = (p1.y - p0.y) / (p1.x - p0.x);
    float b = p1.y / k * p1.x;
    float right = k * p2.x + b;
    if (p2.y - right > 0)
    {
        return 0;
    }
    return 1;

}

void qsort(int start, int finish, std::vector<point>& v)
{
    if (finish - start == 2) return;
    int pivot = (start + finish) / 2;
    while (start <= finish)
    {
        while(way()])
        {

    }

    while ()
}

int main()
{
    int n = 10;
    std::vector<point> points(0);
    for (int i = 0; i < n; i++)
    {
        point a;
        while (!check(points, a))
        {
            a.random();
        }
        points.push_back(a);
    }

    int buf1 = 0;
    int buf2 = 0;
    for (int i = 0; i < points.size(); i++)
    {
        if (points[i].x < buf1)
        {
            buf1 = points[i].x;
            buf2 = i;
        }
    }
