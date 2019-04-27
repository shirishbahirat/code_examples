class Solution {
public:
  int uniqueMorseRepresentations(vector<string> &words) {

    map<char, string> m2s;
    set<string> m2s_set;

    vector<string> morse{".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                         "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                         "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                         "...-", ".--",  "-..-", "-.--", "--.."};
    vector<char> letters{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                         'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                         's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char>::iterator im = letters.begin();

    for (vector<string>::iterator it = morse.begin(); it != morse.end(); ++it) {
      m2s[*im] = *it;
      ++im;
    }

    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it) {
      string word = *it;
      string transformation = "";
      for (int j = 0; j < word.size(); ++j) {
        transformation += m2s[word[j]];
      }
      m2s_set.insert(transformation);
    }

    return m2s_set.size();
  }
};