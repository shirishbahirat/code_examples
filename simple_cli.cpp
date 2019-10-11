#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]) {
  queue<char> data_q;
  cout << ">> ";

  while (true) {
    string line;
    getline(cin, line);

    if (line.empty())
      cout << ">> ";
    else
      cout << ">> ";

    if (line == "exit")
      break;
    else if (line == "print")
      cout << line;
  }
  return 0;
}