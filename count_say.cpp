#include <iostream>

using namespace std;

class Solution
{
public:
  string countAndSay(int n)
  {

    string input = to_string(n);
    string result = "";
    int duplicate = 0;
    int i;

    for (i = 1; i < input.size(); ++i)
    {
      if (input[i - 1] != input[i])
      {
        result += to_string(duplicate + 1);
        result += input[i - 1];
        duplicate = 0;
      }
      else
      {
        duplicate += 1;
      }
    }
    result += to_string(duplicate + 1);
    result += input[i - 1];

    return result;
  }
};

int main(int argc, char const *argv[])
{

  int n = 1;

  Solution *soln = new Solution();

  string say = soln->countAndSay(n);

  cout << say << endl;

  return 0;
}
