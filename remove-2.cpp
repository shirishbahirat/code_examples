#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
  }
};

int main(int argc, char const *argv[]) {

  Solution *sln = new Solution();

  vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
  // vector<int> nums{3};

  sln->removeElement(nums, 2);

  return 0;
}
