#include <iostream>

using namespace std;

class Solution
{
public:
  int strStr(string haystack, string needle)
  {

    if ((haystack.size() == 0) && (needle.size() == 0))
    {
      return 0;
    }

    int idx = 0;
    int results = -1;
    int start = 0;

    for (int i = 0; i < haystack.size(); ++i)
    {
      cout << haystack[i];
      if (haystack[i] == needle[idx])
      {
        idx++;
        if (idx == 1)
        {
          start = i;
        }
        if (idx == needle.size())
        {
          results = start;
        }
      }
      else
      {
        idx = 0;
      }
    }

    cout << endl;

    return results;
  }
};

int main(int argc, char const *argv[])
{

  Solution *soln = new Solution();

  int out = soln->strStr("", "a");

  cout << out << endl;

  return 0;
}
