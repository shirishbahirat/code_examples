#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int sumOfDigits(vector<int> &A) {

    int min = 0x7FFFFFFF;
    vector<int> digits;
    int sum = 0;

    for (vector<int>::iterator it = A.begin(); it != A.end(); ++it) {

      if (min > *it)
        min = *it;
    }

    while (min != 0) {
      digits.push_back(min % 10);
      min = min / 10;
    }

    for (int i = digits.size() - 1; i >= 0; i--) {
      sum += digits[i];
    }

    if (sum % 2)
      return 0;
    else
      return 1;
  }
};

int main(int argc, char const *argv[]) {

  Solution *sln = new Solution();

  vector<int> items{99, 77, 33, 66, 55};

  sln->sumOfDigits(items);

  return 0;
}
