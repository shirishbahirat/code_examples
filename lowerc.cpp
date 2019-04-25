#include <algorithm>
#include <locale>

class Solution {
public:
  string toLowerCase(string str) {

    if (str.length() == 0)
      return str;

    locale loc;
    for (string::size_type i = 0; i < str.length(); ++i) {
      str[i] = tolower(str[i], loc);
    }
    return str;
  }
};