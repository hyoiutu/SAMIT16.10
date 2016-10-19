#include<iostream>
#include<random>
#include<cmath>
using namespace std;
inline double f(double x){return sqrt(1 - x*x);};
double montecarlo(double begin, double end, int numOfPlot);
double quasiMontecarlo(double begin, double end, int numOfPlot);

double vandercorput(int b, int n,int i=0);

int main(void)
{
  cout << "モンテカルロ法:S=" << 4*montecarlo(0.0,1.0,10000000) << endl;
  cout << "準モンテカルロ法:S=" << 4*quasiMontecarlo(0.0,1.0,10000000) << endl;

}

double montecarlo(double begin, double end, int numOfPlot)
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

    if(f(randTmpX) > randTmpY)
    {
      inX++;
    }
  }
  return Sa * inX / numOfPlot;
}

double quasiMontecarlo(double begin, double end, int numOfPlot)
{
  double Sa = (end-begin) * (end-begin);
  int inX = 0;
  for(int i=0;i<numOfPlot;++i)
  {
    double randTmpX = begin + end*vandercorput(2,i);
    double randTmpY = begin + end*vandercorput(3,i);
    if(f(randTmpX) > randTmpY)
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
