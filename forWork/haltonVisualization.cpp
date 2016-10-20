#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

double vandercorput(int b, int n, int i=0);

int main(int argc, char *argv[])
{
  for(int i=0;i<atoi(argv[1]);++i)
  {
    cout << vandercorput(2, i) << " " << vandercorput(3, i) << endl;
  }
}

double vandercorput(int b, int n, int i)
{
  if(n == 0)
  {
    return 0;
  }
  return (n%b)/pow(b,i+1) + vandercorput(b, n/b, ++i);
}
