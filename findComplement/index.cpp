#include <iostream>

using namespace std;

int findComplement(int num);

int main() {
    cout << findComplement(5) << '\n';

    return 0;
}

int findComplement(int num) {
    int tmp{num};
    int mask{1};

    while (tmp != 0) {
        mask *= 2;
        tmp >>= 1;
    }
    mask -= 1;

    return num ^ mask;
}