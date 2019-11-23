#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }
  void rotate(vector<vector<int>> &matrix) {
    int levels = matrix.size() / 2;
    int last = matrix.size() - 1;
    int level = 0;
    while (level < levels) {
      for (int i = level; i < last; ++i) {
        swap(matrix[level][i], matrix[i][last]);
        swap(matrix[level][i], matrix[last][last - i + level]);
        swap(matrix[level][i], matrix[last - i + level][level]);
      }
      ++level;
      --last;
    }
  }
};
int main(int argc, char const *argv[]) {

  Solution *sln = new Solution();

  vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  sln->rotate(matrix);

  for (int i = 0; i < matrix[0].size(); ++i) {

    for (int j = 0; j < matrix[0].size(); ++j) {

      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
