#include <cstdlib>
#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

double fact_n;

double factorial(int n); // To calculate the factorial
double nCk(int n,int k);
int rand();

int main()
{
  int n = 18;
  fact_n=factorial(n);

  int per[n+1];
  for(int j=0;j<n+1;j++)
  {
    per[j]=0;
  }

  srand((unsigned)time(0));


  for(int xx=0;xx<999999;xx++)
  {
    double k_rand = rand();
    //cout << k_rand << endl;
    k_rand /=32767.0;
    int k = 0;
    int i = 0;
    double nck = 0;
    for(i=0;i<=n;i++)
    {
      double nck_1 = nCk(n,i)/(pow(2.0,n));
      if(k_rand>=nck && k_rand<(nck_1+nck))
      {
        break;
      }
      nck += nck_1;
    }
    k = i;
    per[k]++;
  }


  for(int j=0;j<n+1;j++)
  {
    cout << j << " : " << per[j] << endl;
  }


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
  ans = fact_n/(factorial(k)*factorial(n-k));
  return ans;
}
