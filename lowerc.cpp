#include <algorithm>
#include <iostream>
#include <locale>

using namespace std;

class change_case {
public:
  change_case() {}
  ~change_case() {}

  string to_lower_case(string str) {

    if (str.length() == 0)
      return str;

    locale loc;
    for (string::size_type i = 0; i < str.length(); ++i) {
      str[i] = tolower(str[i], loc);
    }
    return str;
  }
};

int main(int argc, char const *argv[]) {
  change_case *cgc = new change_case();

  cout << cgc->to_lower_case("ShIrIsh") << endl;

  return 0;
}