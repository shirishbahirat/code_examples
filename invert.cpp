#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {

    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0, k = A[i].size() - 1; j < k; ++j, --k) {

        int temp = A[i][j];
        A[i][j] = A[i][k];
        A[i][k] = temp;
      }

      for (int j = 0; j < A[i].size(); ++j) {

        A[i][j] ^= 1;
      }
    }

    return A;
  }
};
int main(int argc, char const *argv[]) {

  Solution *sln = new Solution();

  vector<vector<int>> items{
      {1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}};

  sln->flipAndInvertImage(items);

  return 0;
}
