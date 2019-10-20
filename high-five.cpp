#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> highFive(vector<vector<int>> &items) {

    vector<int> student_id(1000, 0);
    vector<int> student_marks(1000, 0);
    vector<int> subject_index(1000, 0);
    vector<int> minimum_marks(1000, 0xFFFF);

    for (vector<vector<int>>::iterator it = items.begin(); it != items.end();
         ++it) {

      vector<int> marks = *it;

      if (minimum_marks.at(marks[0]) > marks[1]) {
        minimum_marks.at(marks[0]) = marks[1];
        cout << "Minimum  " << minimum_marks[marks[0]] << endl;
      }

      subject_index[marks[0]]++;

      student_marks[marks[0]] += marks[1];
      cout << student_marks[marks[0]] << endl;

      if (subject_index[marks[0]] > 5) {
        student_marks[marks[0]] -= minimum_marks[marks[0]];
      }
    }

    for (int i = 0; i < 1000; ++i) {
      student_marks[i] /= 5;
      cout << student_marks[i] << " ";
    }

    return items;
  }
};

int main(int argc, char const *argv[]) {

  Solution *sln = new Solution();

  vector<vector<int>> items{{1, 91},  {1, 92},  {2, 93}, {2, 97},
                            {1, 60},  {2, 77},  {1, 65}, {1, 87},
                            {1, 100}, {2, 100}, {2, 76}};

  sln->highFive(items);

  return 0;
}
