#include<iostream>
#include<random>
#include<cmath>
#include<cstdio>
using namespace std;
auto f = [](double x){return sqrt(1 - x*x);};
auto ex4f = [](double x){return x*x*exp(-x*x);};
double montecarlo(double begin, double end, int numOfPlot, auto function);
double quasiMontecarlo(double begin, double end, int numOfPlot, auto function);

double vandercorput(int b, int n,int i=0);

double ex4(int numOfPlot);
double ex4Test(int numOfPlot);

int main(void)
{
  printf("モンテカルロ法:S=%.5f\n",4*montecarlo(0.0,1.0,100000, f));
  printf("準モンテカルロ法:S=%.5f\n",4*quasiMontecarlo(0.0,1.0,100000, f));
  printf("演習4の答えはS=%.5f\n",ex4(100000));
  printf("演習4の答えはS=%.5f\n",ex4Test(100000));
  for(int i=0;i<50;++i)
  {
    cout << vandercorput(2,i) << " ";
  }
  cout << endl;
}

double montecarlo(double begin, double end, int numOfPlot, auto function)
{
  random_device rnd;
  mt19937 mt(rnd());
  uniform_real_distribution<double> generate(begin, end);
  double Sa = (end-begin) * (end-begin);
  int inX = 0;
  for(int i=0;i<numOfPlot;++i)
  {
    double randTmpX = generate(mt);
    double randTmpY = generate(mt);

    if(function(randTmpX) >= randTmpY)
    {
      inX++;
    }
  }
  return Sa * inX / numOfPlot;
}

double quasiMontecarlo(double begin, double end, int numOfPlot, auto function)
{
  double Sa = (end-begin) * (end-begin);
  int inX = 0;
  for(int i=0;i<numOfPlot;++i)
  {
    double randTmpX = begin + end*vandercorput(2,i);
    double randTmpY = begin + end*vandercorput(3,i);
    if(function(randTmpX) >= randTmpY)
    {
      inX++;
    }
  }
  return Sa * inX / numOfPlot;
}


double vandercorput(int b, int n, int i)
{
  if(n == 0)
  {
    return 0;
  }
  return (n%b)/pow(b,i+1) + vandercorput(b, n/b, ++i);
}

double ex4(int numOfPlot)
{
  return montecarlo(0,1,numOfPlot,ex4f) * montecarlo(0,2,numOfPlot,ex4f) * montecarlo(0,3,numOfPlot,ex4f);
}

double ex4Test(int numOfPlot)
{
  auto ex4true = [](double x, double y, double z){return x*x*y*y*z*z*exp(-(x*x+y*y+z*z));};
  double Va = 1*2*3/exp(1);
  int inside = 0;
  for(int i=0;i<numOfPlot*3;++i)
  {
    double randTmpX = vandercorput(2,i);
    double randTmpY = 2*vandercorput(3,i);
    double randTmpZ = 3*vandercorput(5,i);
    double randTmpZZ = vandercorput(7,i)/exp(1);
    if(ex4true(randTmpX,randTmpY,randTmpZ) >= randTmpZZ)
    {
      inside++;
    }
  }
  return Va * inside / (numOfPlot*3);
}
