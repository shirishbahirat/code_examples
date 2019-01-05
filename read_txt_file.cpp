#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ifstream file("data.txt");
  string str = "";
  string::size_type sz;

  uint32_t line_number = 4;

  while (std::getline(file, str)) {
    cout << str << endl;

    istringstream buf(str);
    istream_iterator<string> beg(buf), end;

    vector<string> tokens(beg, end);

    for (auto &s : tokens)
      cout << atof(s.c_str()) << " " << flush;

    cout << endl;
  }
}