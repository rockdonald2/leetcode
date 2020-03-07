#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::stack;
using std::vector;

vector<int> asteroidCollision(vector<int>& asteroids) {
	stack<int> s;

	for (auto i = 0; i < asteroids.size(); ++i) {
		if (s.empty() || asteroids[i] > 0) {
			s.push(asteroids[i]);
		}
		else {
			while (true) {
				int peek = s.top();

				if (peek < 0) {
					s.push(asteroids[i]);
					break;
				}
				else if (peek == -asteroids[i]) {
					s.pop();
					break;
				}
				else if (peek > -asteroids[i]) {
					break;
				}
				else {
					s.pop();
					
					if (s.empty()) {
						s.push(asteroids[i]);
						break;
					}
				}
			}
		}
	}

	vector<int> return_arr(s.size());

	for (int i = s.size() - 1; i >= 0; --i) {
		return_arr[i] = s.top();
		s.pop();
	}

	return return_arr;
}

int main() {
	vector<int> asteroids{ 5, 10, -5 };

	vector<int> return_arr{ asteroidCollision(asteroids) };

	for (auto it = return_arr.begin(); it != return_arr.end(); ++it) cout << *it << " ";

	return 0;
}