int kthFactor(int n, int k) {
    int c = 0;
    int i = 0;
    bool found = false;

    while (i <= (n / 2) && !found) {
        ++i;
        if (!(n % i)) {
            ++c;
        }

        found = (c == k);
    }

    if (found) {
        return i;
    } else if (++c == k) {
        return n;
    } else {
        return -1;
    }
}