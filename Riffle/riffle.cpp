#include <cstdlib>
#include <iostream>
#include <ctime>
#include <math.h>
#include <vector>
using namespace std;

double fact_n;

int position_in_vect(std::vector<unsigned int> v , int num);
double factorial(int n); // To calculate the factorial
double nCk(int n,int k);
int per_to_index(int * per, int n);
int rand();

int main()
{
  int n = 5;
  double x,y=0;
  fact_n=factorial(n);

  int deck[n];
  int deck_k[n];
  int deck_n_k[n];
  int per[n+1];
  for(int j=0;j<n+1;j++)
  {
    per[j]=0;
    deck_n_k[j]=0;
    deck_k[j]=0;
    deck[j]=0;
  }

  srand((unsigned)time(0));


  for(int xx=0;xx<10;xx++)
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

    cout << k << endl;
    /**for(int j=0;j<n+1;j++)
    {
      cout << j << " : " << per[j] << "    " << (int)(999999*nCk(n,j)/(pow(2.0,n))) << endl;
    }
  */
    x=k;
    y=n-k;
    for(int j=1;j<=k;j++)
    {
        deck_k[j-1] = j;
    }
    int arbit=0;
    for(int j=k+1;j<=n;j++)
    {
        deck_n_k[arbit] = j;
        arbit++;
    }

  /**  for(int aa=0;aa<k;aa++)
    {
      cout << deck_k[aa] << " ";
    }
    std::cout << '\n';

    for(int aa=0;aa<n-k;aa++)
    {
      cout << deck_n_k[aa] << " ";
    }
    std::cout << '\n';
  */

    for(i=0;i<n;i++)
    {
      double g_rand = rand();
      g_rand /= 32767.0;

      if(g_rand>=0 && g_rand<=(x/(x+y)))
      {
        deck[i] = deck_k[(int)(x-1)];
        x--;
      }
      else
      {
        deck[i] = deck_n_k[(int)(y-1)];
        y--;
      }
    }

    cout << endl;
    cout << endl;

    for(int j=0;j<n;j++)
    {
      cout << deck[j] << " ";
    }

    int index_1 = per_to_index(deck,n);
    cout << index_1 << endl;
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


int per_to_index(int * per, int n)
{
  unsigned int i;
  vector<unsigned int> deck_1;
  double index = 0;
  // set some values (from 1 to 10)
  for (i=1; i<=n; i++) deck_1.push_back(i);

  /**cout << "Deck contains:";
  for (i=0; i<deck_1.size(); i++)
    cout << " " << deck_1[i];
  cout << endl;


  cout << "Permutation :";
  for(int j=0;j<n;j++)
    cout << " " << per[j];
  cout << endl;
*/
  for(int jj=1;jj<n;jj++)
  {
    double n_1_fac = factorial(n-jj);
    //cout << n_1_fac;
    int posi = position_in_vect(deck_1 , per[jj-1]);
    //cout << " " << posi ;
    //cout << " " << index << endl;
    index += n_1_fac*(posi);
    deck_1.erase(deck_1.begin()+posi);
  }

  return (int)index;
}

int position_in_vect(std::vector<unsigned int> v , int num)
{
  int pos = 0;
  for(int jjj=0;jjj<v.size();jjj++)
  {
    if(v[jjj] == num)
    {
      pos = jjj;
      break;
    }
  }
  return pos;

}
