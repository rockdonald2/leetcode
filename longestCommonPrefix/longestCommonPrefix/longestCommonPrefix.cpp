#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

constexpr int CHAR_SIZE{ 128 };

class Trie {
public:
	// létrehozunk két darab tagváltozót, egy bool-t, amely jelzi, hogy véget ért-e a szó behelyezéskor, kereséskor lesz hasznos, a másik pedig a Node-k tárolására van
	bool isEndOfWord;
	Trie* character[CHAR_SIZE]; // azért van a CHAR_SIZE konstanst, mert így fogjuk map-ként indexelni a betüket

	// konstruktőr, amely inicializálja a tagváltozókat, a bool-t false-ra, a Node-kat pedig nullptr-re
	Trie() {
		this->isEndOfWord = false;

		for (int i = 0; i < CHAR_SIZE; ++i) {
			character[i] = nullptr;
		}
	}

	void insert(string key) {
		if (key == "") {
			return;
		}

		// kezdjük a root-tól
		Trie* curr = this;

		// végig iterálunk az adott string-en
		for (int i = 0; i < key.length(); ++i) {
			// abban az esetben, ha az adott node nem létezik, akkor hozzáadjuk, és hozzárendelünk egy üres node-t.
			if (curr->character[key[i]] == nullptr) {
				curr->character[key[i]] = new Trie();
			}

			// átlépünk a következő node-ra.
			curr = curr->character[key[i]];
		}

		// jelöljük a szó végét
		curr->isEndOfWord = true;
	}

	string getLCP() {
		// abban az esetben, ha a Trie nem létezne.
		if (this == nullptr) {
			return "";
		}

		// létrehozzuk a végső prefixet tartalmazó stringet
		string lcp{ "" };

		// elkezdjük végigjárni az összes node-t
		Trie* curr = this;
		for (int i = 0, flag = false; i < CHAR_SIZE; ++i) {
			// ha az adott node nem üres
			if (curr->character[i] != nullptr) {
				// azért van szükség az if-else-re, mert ha két prefixet adnánk hozzá egy node-ról
				if (!flag) {
					lcp.push_back(static_cast<char>(i));
					flag = true;
				}
				else {
					lcp.pop_back();
					break;
				}
			}

			// ha az i=127
			if (i == CHAR_SIZE - 1) {
				// ha az lcp üres, tehát végig üres volt minden node, akkor lépjünk ki a loopból
				if (lcp == "") break;

				// átlépünk a következő char node-jára
				curr = curr->character[lcp.back()];

				// ha az adott node egy szó vége, akkor lépjünk ki,
				// tudjuk, hogy nincs értelme tovább nézni, hiszen az egyik szó végéhez értünk
				if (curr->isEndOfWord) {
					break;
				}

				// reseteljük az iterátort és a flag-t, amely számon tartja, hogy 1 vagy több node-dal találkoztunk
				i = 0;
				flag = false;
			}
		}

		return lcp;
	}
};

string longestCommonPrefix(vector<string>& strs) {
	if (strs.empty()) {
		return "";
	}

	Trie t;
	
	for (int i = 0; i < strs.size(); ++i) {
		// ha üres lenne bármelyik string, akkor üres lcp-t térítünk
		if (strs[i] == "") {
			return "";
		}

		t.insert(strs[i]);
	}

	return t.getLCP();
}

int main() {
	vector<string> strs{ "", "b" };

	cout << longestCommonPrefix(strs) << endl;

	return 0;
}