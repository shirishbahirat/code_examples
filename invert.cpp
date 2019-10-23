#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) { return A; }
};

int main(int argc, char const *argv[]) {

  Solution *sln = new Solution();

  vector<vector<int>> items{{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};

  sln->flipAndInvertImage(items);

  return 0;
}
