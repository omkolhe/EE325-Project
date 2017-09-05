#include <iostream>
#include <vector>
using namespace std;

int main ()
{
  unsigned int i;
  vector<unsigned int> deck;

  // set some values (from 1 to 10)
  for (i=1; i<=10; i++) deck.push_back(i);

  // erase the 6th element
  deck.erase (deck.begin()+5);

  // erase the first 3 elements:
  deck.erase (deck.begin(),deck.begin()+3);

  cout << "Deck contains:";
  for (i=0; i<deck.size(); i++)
    cout << " " << deck[i];
  cout << endl;

  return 0;
}
