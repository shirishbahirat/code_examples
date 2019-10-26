class Solution {
public:
  int fixedPoint(vector<int> &A) {

    int match = -1;

    for (int i = 0; i < A.size(); i++) {
      if (A[i] == i) {
        match = i;
        break;
      }
    }

    return match;
  }
};