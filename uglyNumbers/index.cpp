#include <iostream>

using namespace std;

bool isUgly(int num);

int main() {
    cout << isUgly(0) << '\n';

    return 0;
}

bool isUgly(int num) {
    while (num > 1) {
        if (!(num % 2)) {
            num /= 2;
            continue;
        } else if (!(num % 3)) {
            num /= 3;
            continue;
        } else if (!(num % 5)) {
            num /= 5;
            continue;
        } else {
            return false;
        }
    }

    return num != 0;
}