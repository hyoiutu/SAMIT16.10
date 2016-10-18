#include<iostream>
#include<cmath>
using namespace std;

inline double f(double x){ return sqrt(1 - x*x);}

double trapezoidalRule(int begin, int end, int n);
double trapezoidalArea(double upper, double lower, double height);

int main(void)
{
  cout << "S = " << trapezoidalRule(0, 1, 1000) * 4 << endl;
}

double trapezoidalRule(int begin, int end, int n)
{
  double step = (end - begin)/(double)n;
  double area = 0.0;
  for(double i = begin+step; i <= end; i+= step)
  {
    area += trapezoidalArea(f(i), f(i-step), step);
  }
  return area;
}

double trapezoidalArea(double upper, double lower, double height)
{
  return (upper + lower) * height / 2;
}
