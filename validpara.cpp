#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValid(std::string s) {
    std::vector<char> stk;
    for (char c : s) {
      switch (c) {
      case '(':
      case '{':
      case '[':
        stk.push_back(c);
        break;
      case ')':
        if (stk.empty() || stk.back() != '(')
          return false;
        stk.pop_back();
        break;
      case '}':
        if (stk.empty() || stk.back() != '{')
          return false;
        stk.pop_back();
        break;
      case ']':
        if (stk.empty() || stk.back() != '[')
          return false;
        stk.pop_back();
        break;
      }
    }
    return stk.empty();
  }
};

int main(int argc, char const *argv[]) {
  string s = "()([)]{}";

  Solution *sln = new Solution();

  bool res = sln->isValid(s);

  cout << res << endl;

  return 0;
}