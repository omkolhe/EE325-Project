#include <cstdlib>
#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

double factorial(int n); // To calculate the factorial
double nCk(int n,int k);
int rand();

int main()
{
  int n = 6;
  cout << nCk(4,2) << endl;
  srand((unsigned)time(0));
  double k_rand = rand();
  cout << k_rand << endl;
  k_rand /=32767.0;
//  k_rand = 0.1;
  cout << k_rand << endl;
  int k = 0;
  int i = 0;
  double nck = 0;
  for(i=0;i<n;i++)
  {
    cout << nck << " ";
    double nck_1 = nCk(n,i+1)/(pow(2.0,n));
    cout << nck_1 << endl;
    if(k_rand>=nck && k_rand<(nck_1+nck))
    {
      break;
    }
    nck += nck_1;
  }
  k = i+1;
  cout << k << endl;
  return 0;
}

double factorial(int n)
{
  double fact =1;
  for(int j=2;j<=n;j++)
  {
    fact *= j;
  }

  return fact;
}

double nCk(int n,int k)
{
  double ans;
  ans = factorial(n)/(factorial(k)*factorial(n-k));
  return ans;
}

/**  if(i==0)
  {
    if(k_rand>=0 && k_rand<nck_1)
    {
      break;
    }
  }
  else
  {
    if(k_rand>=nck && k_rand<(nck_1+nck))
    {
      break;
    }
  } */
