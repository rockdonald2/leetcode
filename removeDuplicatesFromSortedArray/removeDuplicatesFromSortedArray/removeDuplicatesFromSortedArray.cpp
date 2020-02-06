#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // early exit, abban az esetben ha üres lenne az argumentum vektor
        if (nums.size() == 0) return 0;

        // első változó, amely az egyedi elemeket fogja számolni
        int i = 0;

        // második változó, amely az aktuális vektor elemet fogja mutatni
        for (int j = 1; j < nums.size(); ++j) {
            // abban az esetben ha, nem lenne duplikátum, behelyezi az utolsó egyedi elem utáni helyre a következő egyedit
            if (nums[i] != nums[j]) {
                ++i;
                nums[i] = nums[j];
            }
        }

        // mivel egy vektor hosszát térítjük, ezért +1 hozzáadunk, hiszen 0-tól van indexelve.
        return i + 1;
    }
};

int main() {
    Solution sol;

    vector<int> nums{ 1, 1, 2, 3, 4, 4, 4};

    int len = sol.removeDuplicates(nums);

    // kiírja a consolera, az első "len" elemet, amelyek a behelyezések miatt mind egyediek kell legyenek.
    for (int i = 0; i < len; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}