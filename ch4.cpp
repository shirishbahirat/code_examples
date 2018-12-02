#include <iostream>

using namespace std;


uint32_t parity(uint32_t x) {
  uint32_t result = 0;
  while (x) {
  	cout << "input " << x << " result " << result << " last bit " << (x & 1) << " xor " << (result ^ (x & 1)) << endl;
    result ^= (x & 1);
    x >>= 1;
  }
  return result;
}

uint32_t parity_optimized(uint32_t x) {
  uint32_t result = 0;
  while(x) {
  		result ^= 1;
  		x &= (x - 1);
  }


  return result;
}

uint32_t count_bits(uint32_t x) {
	uint32_t count = 0;

	while(x) {
		count += (x & 1);
		x >>= 1;
	}

	return count;
}


int main(int argc, const char* argv[])
{

	uint32_t xor_parity = parity(0x1F);

	uint32_t xor_parity_optimized = parity_optimized(0x1F);

	cout << "party " << xor_parity << " " <<  xor_parity_optimized << endl;

	cout << "bit count " << count_bits(0xFFFFFFFF) << endl;

	return 0;
}