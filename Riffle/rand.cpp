#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
int i, r;

srand((unsigned)time(0));

for(i = 0; i <= 20; i++)
{
  cout << rand() << endl;
}
return 0;
}
