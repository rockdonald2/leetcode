class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max{nums[0]};
        int curr{max};
        
        for (int i = 1; i < nums.size(); ++i) {
            if (curr < 0) {
                curr = 0;
            }
            
            curr += nums[i];
            max = (curr > max ? curr : max);
        }
        
        return max;
    }
};