#include<iostream>
#include<random>
#include<cstdlib>
using namespace std;
const int N = 100;
int main(int argc, char *argv[])
{
  random_device rnd;
  mt19937 mt(rnd());
  uniform_real_distribution<double> generate(0.0, 1.0);
  double x,y;
  for(int i=0;i<atoi(argv[1]);++i)
  {
    x = generate(mt);
    y = generate(mt);
    cout << x << " " << y << endl;
  }
}
