#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
	int set = 0;
	constexpr int MAX_BITS = 32;

	// eltolja jobbra az n bitjeit annyival, amekkora az i iterátor, majd összeveti az 1-el, aminek csak az utolsó bitje 1
	for (int i = 1; i <= MAX_BITS; ++i) {
		if ((n >> (i - 1) & 1)) {
			set += 1;
		}
	}

	return set;
}

int main() {
	uint32_t n{ 11 };

	cout << hammingWeight(n) << endl;

	return 0;
}