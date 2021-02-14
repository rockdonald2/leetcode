void insertionSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            int tmp{nums[i]};
            int j{i - 1};
            
            while (j >= 0 && nums[j] > tmp) {
                nums[j + 1] = nums[j];
                --j;
            }
            
            nums[j + 1] = tmp;
        }
    }
    
    int arrayPairSum(vector<int>& nums) {
        //insertionSort(nums);
        sort(nums.begin(), nums.end());
        
        int maxSum{0};
        for (int i = 0; i < nums.size(); i += 2) {
            maxSum += nums[i];
        }
        
        return maxSum;
    }