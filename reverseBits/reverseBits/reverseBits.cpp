#include <iostream>
// #include <bitset>

using namespace std;

uint32_t reverseBits(uint32_t n) {
	/*bitset<32> bits(n);

	int i = 0;
	int j = 31;

	while (i < j) {
		if (bits[i] != bits[j]) {
			bits.flip(i);
			bits.flip(j);
		}

		++i;
		--j;
	}

	return bits.to_ulong();*/

	uint32_t reversed = 0;
	constexpr int MAX_BITS = 32;

	for (int i = 0; i < MAX_BITS; ++i) {
		// mindegyik bitet 1-el balra tóljuk
		reversed <<= 1;
		// összevessük az n-t az 1-el, majd belemásoljuk a reversed-be
		reversed |= n & 1;
		// mindegyik bitet 1-el jobbra tóljuk
		n >>= 1;
	}

	return reversed;
}

int main() {
	uint32_t n = 4294967293;

	if (reverseBits(n) == 3221225471) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}

	return 0;
}