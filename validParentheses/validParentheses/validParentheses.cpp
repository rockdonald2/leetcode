#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>

using namespace std;

bool isValid(string s) {
	//// alapvetően páratlan hosszú stringet nem lehetnek érvényes zárójelpárok
	//if (s.length() % 2 != 0) {
	//	return false;
	//}

	//// létrehozunk egy map-et, amelynek alapvető funkciója az, hogy tárolja az érvényes zárójel párokat, így lerövidítve az if-else állításokat
	//map<char, char> p;
	//p.insert(pair<char, char>('(', ')')); p.insert(pair<char, char>('[', ']')); p.insert(pair<char, char>('{', '}'));
	//
	//// létrehozunk egy stack-et, amely csakis a zárójelek nyitó részét fogja tartalmazni
	//stack<int> st;
	//for (int i = 0; i < s.size(); ++i) {
	//	// abban az esetben, ha zárójelt nyit, felhelyezzük a stackbe
	//	if (p.find(s[i]) != p.end()) {
	//		st.push(s[i]);
	//	}
	//	// abban az esetben, ha nem nyitó rész, megvizsgáljuk, van-e valami egyáltalán a stackben, vagy az utolsó felhelyezett zárójel, az adott zárójel párja
	//	else if (st.empty() || s[i] != p[st.top()]) {
	//		return false;
	//	}
	//	// abban az esetben, ha párja levesszük az adott nyitó részt
	//	else {
	//		st.pop();
	//	}
	//}

	//// ha érvényes állításunk van, akkor a stack a végén üres kell legyen
	//return st.empty();

	if (s.length() % 2 != 0) {
		return false;
	}

	vector<char> stack;
	for (int i = 0; i < s.length(); ++i) {
		if (
			s[i] == '(' ||
			s[i] == '[' ||
			s[i] == '{'
			) stack.push_back(s[i]);
		else if (
			stack.empty() || 
			(stack.back() == '(' && s[i] != ')') ||
			(stack.back() == '[' && s[i] != ']') ||
			(stack.back() == '{' && s[i] != '}')
			) return false;
		else stack.pop_back();
	}

	return stack.empty();
}

int main() {
	string s{ "([)]" };

	cout << isValid(s) << endl;

	return 0;
}