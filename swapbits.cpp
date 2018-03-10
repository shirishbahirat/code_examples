#include <iostream>
using namespace std;

int main() {

	int n = 4;
	cout<< (((n&(0b10101010))>>1)|((n&(0b01010101))<<1)) <<endl;

	return 0;
}

