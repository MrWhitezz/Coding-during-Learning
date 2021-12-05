#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct Point
{
    double x;
    double y;
};
double size(Point &p1, Point &p2, Point p3);
double max3(double a, double b, double c);
double dist(Point &p1, Point &p2);
double MaxPg(Point Pg[],int n);
int main()
{
    int n;
    cin >> n;
    Point Pg[n + 1];
    for (int i = 0; i < n; i++)
        cin >> Pg[i].x >> Pg[i].y;
    Pg[n] = Pg[0];
    printf("%.16lf",sqrt(MaxPg(Pg, n)));

    return 0;
}
double size(Point &p1, Point &p2, Point p3)
{
    return abs((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y));
}
double max3(double a, double b, double c)
{
    double temp = a > b ? a : b;
    return temp > c ? temp : c;
}
double dist(Point &p1, Point &p2)
{
    return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double MaxPg(Point Pg[],int n)
{
    int q = 1;
    double ans = 0;
    for (int p = 0; p < n; p++)
    {
        while (size(Pg[p],Pg[p + 1],Pg[q + 1]) > size(Pg[p],Pg[p + 1],Pg[q]))
            q = (q + 1) % n;
        if (size(Pg[p],Pg[p + 1],Pg[q + 1]) == size(Pg[p],Pg[p + 1],Pg[q]))
            ans = max3(ans, dist(Pg[p], Pg[q]), dist(Pg[p + 1], Pg[q + 1]));
        else
            ans = max3(ans, dist(Pg[p], Pg[q]), dist(Pg[p + 1], Pg[q]));
    }
    return ans;
}
