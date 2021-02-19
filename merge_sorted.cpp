#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {

    if (!n)
      return;

    int idx = 0;

    for (int i = 0; i < m; ++i)
    {
      if (nums1.at(i) <= nums2.at(idx))
      {
      }
      else
      {
        int temp = nums1.at(i);
        nums1.at(i) = nums2.at(idx);
        nums2.erase(nums2.begin());
        nums2.at(idx) = temp;
        idx++;
      }
    }

    for (int i = m, j = 0; i < (m + n); ++i, ++j)
    {
      nums1.at(i) = nums2.at(j);
    }
  }
};

int main(int argc, char const *argv[])
{

  vector<int> nums1 = {4, 0, 0, 0, 0, 0};
  int m = 1;
  vector<int> nums2 = {1, 2, 3, 5, 6};
  int n = 5;

  Solution *soln = new Solution();

  soln->merge(nums1, m, nums2, n);

  for (int i = 0; i < m; ++i)
  {
    cout << nums1.at(i) << " ";
  }
  cout << endl;

  for (int i = 0; i < n; ++i)
  {
    cout << nums2.at(i) << " ";
  }
  cout << endl;

  for (int i = 0; i < nums1.size(); ++i)
  {
    cout << nums1.at(i) << " ";
  }
  cout << endl;

  return 0;
}