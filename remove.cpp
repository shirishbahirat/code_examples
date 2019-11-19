#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void swap(vector<int>::iterator &ix, vector<int>::iterator &iy) {
    int value = *ix;
    *ix = *iy;
    *iy = value;
  }

  int removeElement(vector<int> &nums, int val) {

    if (nums.empty())
      return 0;

    if (nums.size() == 1) {
      return 0;
    }
    vector<int>::iterator it = nums.end();
    vector<int>::iterator is = nums.begin();
    --it;

    int counter = 0;

    while (it != is) {

      cout << "start ";
      for (vector<int>::iterator im = nums.begin(); im != nums.end(); ++im) {
        cout << *im << " ";
      }
      cout << " p " << *is << " " << *it << endl;

      if (*it == val) {
        --it;
      }
      if (*is != val) {
        ++is;
        ++counter;
      }
      if (*is == val) {
        cout << "swap " << *is << " " << *it << " : " << endl;
        swap(it, is);
      }

      cout << "end ";
      for (vector<int>::iterator im = nums.begin(); im != nums.end(); ++im) {
        cout << *im << " ";
      }
      cout << " p " << *is << " " << *it << " " << counter << endl;
    }

    return counter + 1;
  }
};

int main(int argc, char const *argv[]) {

  Solution *sln = new Solution();

  // vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
  vector<int> nums{3};

  int val = sln->removeElement(nums, 3);

  cout << val << endl;

  for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;

  return 0;
}
