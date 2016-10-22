#include<iostream>
using namespace std;

int convert(int b, int n, int* bitArray);

int main(void)
{
  int bits[100];
  int msb = convert(10,1024,bits);
  for(int i=msb-1;i>=0;--i)
  {
    cout << bits[i] << ",";
  }
  cout << endl;
}

int convert(int b, int n, int* bitArray)
{
  int i;
  for(i=0;n!=0;++i)
  {
    *(bitArray+i) = n%b;
    n /= b;
  }
  return i;
}
