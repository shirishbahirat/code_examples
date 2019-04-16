#include <iostream>
#include <unordered_map>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;


int main(int argc, char const *argv[])
{

	int target(10);
	vector<int> data(10, 0);
	unordered_map<int, int> targets;

	for (std::vector<int>::iterator it = data.begin(); it != data.end(); ++it)
	{
        *it = rand() % 10;
		cout << *it << endl;
	}

	int i;
	for (std::vector<int>::iterator it = data.begin(); it != data.end(); ++it)
	{
		targets[*it] = i++;
	}

	i = 0;
	std::vector<int>::iterator im;
	for (std::vector<int>::iterator it = data.begin(); it != data.end(); ++it)
	{
		im = std::find (data.begin(), data.end(), target - *it);
		if (im != data.end())
		{
			cout << targets[target - *it] << " " << i << " values " << data.at(targets[target - *it]) << " " << data.at(i) << endl;
		}
		++i;
	}


	return 0;
}