#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;


int main(int argc, char* argv[])
{

    ifstream infile("q3.txt");
    string line;
    
    while (getline(infile, line))
    {

        cout << line << endl;
        stringstream ss(line);
        string token = "";
        string last_token = "";
        bool hasduplicate;
        
        while (getline(ss, token, ' '))
        {
        
            if (last_token == token)
            {
                hasduplicate = true;
                cout << "duplicate" << endl;   
            }
            
            cout << token << endl;
            last_token = token;

        }
        
    }

    return 0;
}
