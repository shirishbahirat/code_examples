#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int countCharacters(vector<string> &words, string chars) {

    int char_count = 0;
    int counter = 0;

    for (int j = 0; j < words.size(); ++j) {

      for (int i = 0; i < words[j].length(); ++i) {

        int instance_word =
            count(words[j].begin(), words[j].end(), words[j][i]);
        int instance_char = count(chars.begin(), chars.end(), words[j][i]);

        if ((chars.find(words[j][i]) != string::npos) &&
            (instance_word <= instance_char))
          counter++;
      }

      cout << words[j].length() << " " << counter << " " << words[j].length()
           << endl;

      if (counter == words[j].length()) {
        char_count += counter;
      }
      counter = 0;
    }

    return char_count;
  }
};

int main(int argc, char const *argv[]) {

  Solution *sln = new Solution();

  vector<string> words{"cat", "bt", "hat", "tree"};
  string chars = "atach";

  int val = sln->countCharacters(words, chars);

  cout << val << endl;

  return 0;
}
