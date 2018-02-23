#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <vector>


void tokenize(std::string const & line, std::vector<std::string> &cmds)
{

    std::istringstream iss(line);

    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>()); 
                                 
    for (std::string result:results)
    {
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        std::cout << result << std::endl;
        cmds.push_back(result);
    }

}

void process(std::string const & line)
{
   std::vector<std::string> cmds;

   tokenize(line, cmds);

    for (std::string cmd:cmds)
    {
        std::cout << cmd << std::endl;
    }

}

int main(int argc, const char* argv[])
{
    for (std::string line; std::cout << "mp > " && std::getline(std::cin, line); )
    {
        if ((line == "exit") || (line == "quit"))
            break;

        if (!line.empty()) { process(line); }
    }

    std::cout << "Goodbye.\n";
}

