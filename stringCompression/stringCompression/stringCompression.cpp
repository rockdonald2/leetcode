#include <iostream>
#include <vector>

using namespace std;

int compress(vector<char>& chars) {
	// ha üres a vektor akkor térítjük a 0-át
	if (chars.size() == 0) return 0;

	// két mutató, az i az eredeti vektorban való lépegetésre vonatkozik, amely által számoljuk is az adott char előfordulását
	int i = 0, j = 0;
	// a j mutató pedig írásra van, hogy tudjuk hova kell beírni a következő chart és utána előfordulásának gyakoriságát

	while (i < chars.size()) {
		// lementjük a keresendő chart, és létrehozzuk a számláló változót
		char currentCh = chars[i];
		int c = 0;

		// megszámoljuk hányszor fordul elő az adott char
		while (i < chars.size() && chars[i] == currentCh) {
			++c;
			++i;
		}

		// a jelenlegi j pozícióra beírjuk a keresett chart, majd növeljük a j mutatót
		chars[j++] = currentCh;
		if (c > 1) {
			vector<char> chArray;

			// felbontjuk különböző karaktereket az előfordulási számot, főleg akkor érdekes, ha többször fordul elő, mint 10
			while (c != 0) {
				chArray.push_back(c % 10 + 48);
				c /= 10;
			}

			// hozzáadjuk a jelenlegi j pozícióra előfordulását, majd növeljük azt.
			for (int k = chArray.size() - 1; k >= 0; --k) chars[j++] = chArray[k];
		}
	}

	// kitöröljük a felesleges maradék charokat
	int oLength = chars.size();
	while (j < oLength) {
		chars.pop_back();
		++j;
	}

	// térítjük az új hosszt
	return chars.size();
}

int main() {
	vector<char> chars{ 'a', 'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };

	cout << compress(chars) << endl;

	return 0;
}