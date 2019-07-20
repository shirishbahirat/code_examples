#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  static int diff(vector<int> &x) { return x[1] - x[0]; }
  static bool cmpfunc(vector<int> &lhs, vector<int> &rhs) {
    return diff(lhs) > diff(rhs);
  }

  void printCosts(vector<vector<int>> &costs) {

    for (int i = 0; i < costs.size(); ++i) {
      vector<int> node{costs.at(i)};
      cout << node.at(0) << " " << node.at(1) << endl;
    }

    cout << " " << endl;
  }

public:
  int twoCitySchedCost(vector<vector<int>> &costs) {

    printCosts(costs);

    sort(costs.begin(), costs.end(), cmpfunc);

    printCosts(costs);

    int result = 0;
    int len = costs.size();
    for (int i = 0; i < len / 2; i++) {
      result += (costs[i][0] + costs[len - i - 1][1]);
    }
    return result;
  }
};

int main(int argc, char const *argv[]) {

  vector<vector<int>> costs{{10, 20}, {30, 200}, {400, 50}, {30, 20}};

  Solution *test = new Solution();

  int result = test->twoCitySchedCost(costs);

  cout << result << endl;

  return 0;
}