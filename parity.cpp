#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArrayByParity(vector<int> &A) {

    vector<int> B;

    for (int i = 0; i < A.size(); ++i) {
      int data = A[i];
      if (A[i] % 2) {
        B.push_back(data);
      } else {
        B.insert(B.begin(), A[i]);
      }
    }

    for (int i = 0; i < B.size(); ++i) {
      cout << B[i] << endl;
    }

    return B;
  }
};

int main(int argc, char const *argv[]) {

  Solution *sln = new Solution();

  vector<int> items{3, 1, 2, 4};

  sln->sortArrayByParity(items);

  return 0;
}
