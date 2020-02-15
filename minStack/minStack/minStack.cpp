#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// using the built-in stack template 

//class MinStack {
//private:
//	stack<int> m_stack;
//	stack<int> m_minstack;
//
//public:
//	MinStack() {}
//
//	void push(int x) {
//		m_stack.push(x);
//
//		if (m_minstack.empty()) {
//			m_minstack.push(x);
//		}
//		else {
//			if (m_minstack.top() >= x) {
//				m_minstack.push(x);
//			}
//		}
//	}
//
//	void pop() {
//		if (m_minstack.top() == m_stack.top()) {
//			m_minstack.pop();
//			m_stack.pop();
//		}
//		else {
//			m_stack.pop();
//		}
//	}
//
//	int top() {
//		if (!m_stack.empty()) {
//			return m_stack.top();
//		}
//		else {
//			return 0;
//		}
//	}
//
//	int getMin() {
//		if (!m_stack.empty()) {
//			return m_minstack.top();
//		}
//		else {
//			return 0;
//		}
//	}
//};

// using normal vectors

class MinStack {
private:
	vector<int> m_stack;
	vector<int> m_minstack;

public:
	MinStack() {}

	void push(int x) {
		if (m_stack.empty()) {
			m_stack.push_back(x);
			m_minstack.push_back(x);
		}
		else {
			m_stack.push_back(x);

			if (m_minstack[m_minstack.size() - 1] >= x) {
				m_minstack.push_back(x);
			}
		}
	}

	void pop() {
		if (m_stack[m_stack.size() - 1] == m_minstack[m_minstack.size() - 1]) {
			m_stack.pop_back();
			m_minstack.pop_back();
		}
		else {
			m_stack.pop_back();
		}
	}

	int top() {
		if (!m_stack.empty()) {
			return m_stack[m_stack.size() - 1];
		}
		else {
			return 0;
		}
	}

	int getMin() {
		if (!m_minstack.empty()) {
			return m_minstack[m_minstack.size() - 1];
		}
		else {
			return 0;
		}
	}
};

int main() {
	MinStack* obj = new MinStack();
	obj->push(2); obj->push(0); obj->push(3); obj->push(0);
	cout << obj->getMin() << endl;
	obj->pop();
	cout << obj->getMin() << endl;
	obj->pop();
	cout << obj->getMin() << endl;
	obj->pop();
	cout << obj->getMin() << endl;

	return 0;
}