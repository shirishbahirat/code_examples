#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char> &s) {

  vector<char>::iterator ix = s.end() - 1;

  for (vector<char>::iterator it = s.begin(); it < (s.begin() + s.size() / 2);
       it++) {
    char temp = *it;
    *it = *ix;
    *ix = temp;
    ix--;
  }
}

int main(int argc, char const *argv[]) {
  vector<char> s{'h', 'e', 'l', 'l', 'o'};

  reverseString(s);

  for (vector<char>::iterator it = s.begin(); it != s.end(); ++it) {
    cout << *it << endl;
  }

  return 0;
}