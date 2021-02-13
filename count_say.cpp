#include <iostream>

using namespace std;

class Solution
{
public:
  string countAndSay(int n) { return "1"; }
};

int main(int argc, char const *argv[])
{

  int n = 11111;

  Solution *soln = new Solution();

  string say = soln->countAndSay(n);

  cout << say << endl;

  return 0;
}
