class Solution {
public:
  int romanToInt(string s) {

    map<char, int> rchar;
    rchar['I'] = 1;
    rchar['V'] = 5;
    rchar['X'] = 10;
    rchar['L'] = 50;
    rchar['C'] = 100;
    rchar['D'] = 500;
    rchar['M'] = 1000;
    int number = 0, i = 0;

    if (s.length() <= 1) {
      return rchar[s.at(0)];
    } else {
      while (i < s.size()) {
        if (rchar[s[i]] < rchar[s[i + 1]]) {
          number += rchar[s[i + 1]] - rchar[s[i]];
          i += 2;
        } else {
          number += rchar[s[i]];
          i++;
        }
      }
      return number;
    }
  }
};