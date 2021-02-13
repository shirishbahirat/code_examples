#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {

    if (nums.size() <= 1)
      return nums.size();

    if (nums.size() > 1)
    {
      vector<int>::iterator first = nums.begin();
      vector<int>::iterator second = nums.begin() + 1;

      while (second != nums.end())
      {
        if (*first == *second)
        {
          nums.erase(second);
        }
        else
        {
          first++;
          second++;
        }
      }
    }

    return nums.size();
  }
};

int main(int argc, char const *argv[])
{

  vector<int> nums = {0, 0, 1, 1, 1, 2, 3, 3, 4};

  Solution *sn = new Solution();

  sn->removeDuplicates(nums);

  for (vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
  {
    cout << *i << endl;
  }

  return 0;
}