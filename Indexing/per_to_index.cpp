#include <iostream>
#include <vector>
using namespace std;

double factorial(int n); // To calculate the factorial
int position_in_vect(std::vector<unsigned int> v , int num);

int main ()
{
  unsigned int i;
  vector<unsigned int> deck;
  int n = 5; //Number of cards
  int per[] = {5,4,3,2,1}; //The permutation of the cards
  double index = 0;
  // set some values (from 1 to 10)
  for (i=1; i<=n; i++) deck.push_back(i);

  cout << "Deck contains:";
  for (i=0; i<deck.size(); i++)
    cout << " " << deck[i];
  cout << endl;

  cout << "Permutation :";
  for(int j=0;j<n;j++)
    cout << " " << per[j];
  cout << endl;

  for(int j=1;j<n;j++)
  {
    double n_1_fac = factorial(n-j);
    cout << n_1_fac;
    int posi = position_in_vect(deck , per[j-1]);
    cout << " " << posi ;
    cout << " " << index << endl;
    index += n_1_fac*(posi);
    deck.erase(deck.begin()+posi);
  }

  cout << index;



  return 0;
}

int position_in_vect(std::vector<unsigned int> v , int num)
{
  int pos = 0;
  for(int j=0;j<v.size();j++)
  {
    if(v[j] == num)
    {
      pos = j;
      break;
    }
  }
  return pos;

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

/**erase the 6th element
deck.erase (deck.begin()+5);

erase the first 3 elements:
deck.erase (deck.begin(),deck.begin()+3);
*/
