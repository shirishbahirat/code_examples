#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> two_sum(vector<int> &numbers, int target) {

  vector<int> result;

  unordered_map<int, int> number_hash;

  for (int i = 0; i < numbers.size(); ++i) {
    number_hash[numbers[i]] = i;
  }

  for (int i = 0; i < numbers.size(); ++i) {
    int result_reminder = target - numbers[i];

    if (number_hash.find(result_reminder) != number_hash.end()) {
      result.push_back(number_hash[result_reminder]);
      result.push_back(i);
      return result;
    }
  }
  return result;
}

int main(int argc, char const *argv[]) {

  vector<int> numbers = {2, 3, 4, 6};
  int target = 9;

  vector<int> result = two_sum(numbers, target);

  cout << result.at(0) << " " << result.at(1) << endl;

  return 0;
}