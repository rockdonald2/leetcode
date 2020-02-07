#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& v) {
    int profit = 0;
    
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > v[i - 1]) {
            profit += (v[i] - v[i - 1]);
        }
    }

    return profit;
}

int main() {
    vector<int> prices{ 1, 7, 2, 3, 6, 7, 6, 7 };

    cout << maxProfit(prices) << endl;

    return 0;
}

/*

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &prices) {
    int i = 0;
    int valley = prices[0];
    int peak = prices[0];
    int profit = 0;

    while (i < prices.size() - 1) {
        while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) {
            ++i;
        }
        valley = prices[i];

        while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) {
            ++i;
        }
        peak = prices[i];

        profit += (peak - valley);
    }

    return profit;
}

int main() {
    vector<int> prices{7, 1, 5, 3, 6, 4};

    cout << maxProfit(prices) << endl;

    return 0;
}

*/