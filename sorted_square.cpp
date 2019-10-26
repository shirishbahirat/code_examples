#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &A) {

    for (int i = 0; i < A.size(); ++i) {
      A[i] = A[i] * A[i];
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < A.size(); ++i) {
      cout << A[i] << endl;
    }

    return A;
  }
};

int main(int argc, char const *argv[]) {

  Solution *sln = new Solution();

  vector<int> items{-4, -1, 0, 3, 10};

  sln->sortedSquares(items);

  return 0;
}
