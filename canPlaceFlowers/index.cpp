bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int i = 0;
    while (i < flowerbed.size() && n) {
        if (flowerbed[i] == 0 &&
            (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) &&
            n > 0 &&
            (i == 0 || flowerbed[i - 1] == 0)) {
            flowerbed[i] = 1;
            --n;
        }

        i += 1;
    }

    if (n == 0) return true;
    else return false;
}