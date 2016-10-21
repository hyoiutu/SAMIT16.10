#include<iostream>
#include<random>
#include<cmath>
using namespace std;
auto f = [](double x){return sqrt(1 - x*x);};
auto ex4f = [](double x){return x*x*exp(-x*x);};
double montecarlo(double begin, double end, int numOfPlot, auto function);
double quasiMontecarlo(double begin, double end, int numOfPlot, auto function);

double vandercorput(int b, int n,int i=0);

double ex4(int numOfPlot);

int main(void)
{
  cout << "モンテカルロ法:S=" << 4*montecarlo(0.0,1.0,10000000, f) << endl;
  cout << "準モンテカルロ法:S=" << 4*quasiMontecarlo(0.0,1.0,10000000, f) << endl;
  cout << "演習4の答えはS=" << ex4(1000000) << endl;
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

    if(function(randTmpX) > randTmpY)
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
    if(function(randTmpX) > randTmpY)
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
  double primarySolution = 0.0;
  double secondarySolution = 0.0;
  double finalSolution = 0.0;

  return montecarlo(0,1,numOfPlot,ex4f) * montecarlo(0,2,numOfPlot,ex4f) * montecarlo(0,3,numOfPlot,ex4f);
}
