#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int searchInsert(vector<int> &nums, int target)
  {

    int idx = 0;
    for (vector<int>::iterator i = nums.begin(); i < nums.end(); ++i)
    {
      if (target <= *i)
      {
        cout << *i << endl;

        break;
      }
      idx++;
    }

    return idx;
  }
};

int main(int argc, char const *argv[])
{

  vector<int> nums = {1, 3, 5, 6};

  Solution *soln = new Solution();

  int idx = soln->searchInsert(nums, 7);

  cout << idx << endl;

  return 0;
}