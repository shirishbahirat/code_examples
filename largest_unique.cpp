class Solution {
public:
  int largestUniqueNumber(vector<int> &A) {

    sort(A.begin(), A.end());
    map<int, int> data;
    int number = -1;

    for (int i = A.size() - 1; i >= 0; --i) {
      data[A[i]] = data[A[i]] + 1;
    }

    for (int i = A.size() - 1; i >= 0; --i) {
      if (data[A[i]] == 1) {
        number = A[i];
        break;
      }
    }

    return number;
  }
};