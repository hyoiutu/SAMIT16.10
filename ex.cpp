#include<iostream>
#include<random>
#include<cmath>
using namespace std;
// 演習1〜3で積分を求める関数
auto f = [](double x){return sqrt(1 - x*x);};
// 演習4で積分を求める関数
auto ex4f = [](double x){return x*x*exp(-x*x);};

/*
モンテカルロ法
  begin: 積分の下端の値
  end: 積分の上端の値
  numOfPlot: プロット点数
  function: 積分を求める関数
  返り値: 積分の近似解
*/
double montecarlo(double begin, double end, int numOfPlot, auto function);

/*
準モンテカルロ法
  begin: 積分の下端の値
  end: 積分の上端の値
  numOfPlot: プロット点数
  function: 積分を求める関数
  返り値: 積分の近似解
*/
double quasiMontecarlo(double begin, double end, int numOfPlot, auto function);

/*
van der corput列
  b: 基数
  n: 逆基底関数の独立変数
  i: 何ビット目か，再帰用の引数なので呼び出す時は指定の必要なし
  返り値: 準乱数
*/
double vandercorput(int b, int n,int i=0);

/*
演習4の関数の積分の近似解
  numOfPlot: プロット点数
  返り値: 近似解
*/
double ex4(int numOfPlot);

int main(void)
{
  // 円周率の近似解を出力する
  cout << "モンテカルロ法:S=" << 4*montecarlo(0.0,1.0,1000,f) << endl;
  cout << "準モンテカルロ法:S=" << 4*quasiMontecarlo(0.0,1.0,1000,f) << endl;
  // 演習4の答えを出力する
  cout << "演習4の答えはS=" << ex4(1000) << endl;

}


double montecarlo(double begin, double end, int numOfPlot, auto function)
{
  // 疑似乱数生成器の準備
  random_device rnd;
  mt19937 mt(rnd());
  uniform_real_distribution<double> generate(begin, end);

  // これ以降を完成させよ(演習1)
  // generate(mt)でbeginからendの範囲の実数乱数を生成できる．

  return 0.0;
}

double quasiMontecarlo(double begin, double end, int numOfPlot, auto function)
{
  // 準モンテカルロ法を完成させよ．(演習3)
  return 0.0;
}


double vandercorput(int b, int n, int i)
{
  // van der corput列を完成させよ．(演習2)
  return 0.0;
}

double ex4(int numOfPlot)
{
  // 関数の近似解を求めよ.(演習4)
  return 0.0;
}
