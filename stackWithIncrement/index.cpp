#include <iostream>
#include <vector>

using namespace std;

class CustomStack {
private:
    vector<int> _data{};
    size_t _maxSize{};

public:
    explicit CustomStack(int maxSize) : _maxSize(maxSize) {
        _data.reserve(maxSize);
    }

    void push(int x) {
        if (_data.size() != _maxSize) {
            _data.push_back(x);
        }
    }

    int pop() {
        if (!_data.empty()) {
            auto elem{_data.back()};
            _data.pop_back();
            return elem;
        } else {
            return -1;
        }
    }

    void increment(int k, int val) {
        int i{0};

        while (i < k && i < _data.size()) {
            _data[i++] += val;
        }
    }

    friend ostream& operator<<(ostream& out, const CustomStack &s) {
        for (const auto &e : s._data) {
            out << e << ' ';
        }

        return out;
    }
};

int main() {
    auto stack{new CustomStack(3)};

    stack->push(1);
    stack->push(2);
    stack->pop();
    stack->push(2);
    stack->push(3);
    stack->push(4);

    cout << *stack << '\n';

    stack->increment(5, 100);

    cout << *stack << '\n';

    stack->increment(2, 100);

    cout << *stack << '\n';

    stack->pop();
    stack->pop();
    stack->pop();

    cout << *stack << '\n';

    return 0;
}