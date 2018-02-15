#include <iostream>
#include <vector>

using namespace std;


int binSearchRecursive(vector<int> my_vector, int x, int start, int size)
{

	if (size >= start)
	{

		int mid = start + ((size - start) / 2); 

		if (mid < my_vector.size())
		{

			cout << "mid point " << mid << " start " << start << endl;

			if (x == my_vector.at(0))
				return 0;

			if (x == my_vector.at(mid))
				return mid;

			if (x > my_vector.at(mid))
				return binSearchRecursive(my_vector , x, mid+1, my_vector.size());

			if (x < my_vector.at(mid))
				return binSearchRecursive(my_vector , x, start, mid-1);
		}
		else
		{
			return -1;
		}

	}

	return -1;
}



int main(int argc, char* argv[])
{


	int my_array[] = {1, 20, 33, 45, 65, 67, 96, 99};
	vector<int> my_vector(my_array, my_array+8);
	vector<int>::const_iterator i;

	for (i = my_vector.begin(); i != my_vector.end(); ++i)
	{
		cout << (*i) << " ";
	}
	cout << endl;

	int index = binSearchRecursive(my_vector , 96, 0, my_vector.size());

	cout << "index of number " << index << endl;

}