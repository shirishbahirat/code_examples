#include <iostream>
#include <bitset>

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


uint32_t swap_bits(uint32_t data, uint32_t bit_a, uint32_t bit_b)
{

	uint32_t bit_mask;

	if ((data >> bit_a & 1) != (data >> bit_b & 1))
	{
		bit_mask = (1 << bit_a) | (1 << bit_b);
	}

	data ^= bit_mask;

	return data;
}



 char reverse_bits(char data) {

   int rev = 0;
   int i = sizeof(data)*8-2;

   while (i >= 0) {
      rev |= (data & 1);
      rev <<= 1;
      data >>= 1;
      i--;
   }

    return rev;
}

uint32_t reverse_digits(uint32_t data)
{

	uint32_t result = 0;

	while(data)
	{
		result = result*10 + data%10;
		data /= 10;
	}

	return result;
}

struct rect {
    int x, y, width, height;
};

bool is_intersect(const rect &r1, const rect &r2)
{
	return r1.x <= r2.x + r2.width && r1.x + r1.width >= r2.x && r1.y <= r2.y + r2.height && r1.y + r1.height >= r2.y;
}

rect intersection(const rect &r1, const rect &r2)
{
    if(!is_intersect(r1, r2)) return (rect){.x = 0,.y = 0, .width = -1, .height = -1};


    return (rect){.x = max(r1.x, r2.x),
    	          .y = max(r1.y, r2.y)
    	          , .width = min(r1.x + r1.width, r2.x + r2.width) - max(r1.x, r2.x),
    	           .height = min(r1.y + r1.height, r2.y + r2.height) - max(r1.y, r2.y)};

}


int main(int argc, const char* argv[])
{

	uint32_t xor_parity = parity(0x1F);

	uint32_t xor_parity_optimized = parity_optimized(0x1F);

	cout << "party " << xor_parity << " " <<  xor_parity_optimized << endl;

	cout << "bit count " << count_bits(0xFFFFFFFF) << endl;

	cout << "swap bits " << 0x1233 << " " << swap_bits(0x1233, 2, 1) << endl;

	cout << "reverse bits " << std::bitset<8>(0x1F) << " " << std::bitset<8>(reverse_bits(0x1F)) << endl;

	cout << "reverse digits " << 1234 << " " << reverse_digits(1234) << endl;

	rect r1 = {10, 12, 5, 6}, r2 = {11, 11, 8, 9};

	rect r3 = intersection(r1, r2);

	cout << "intersection " << r3.x << " " << r3.y << " " << r3.width << " " << r3.height << endl;



	return 0;
}