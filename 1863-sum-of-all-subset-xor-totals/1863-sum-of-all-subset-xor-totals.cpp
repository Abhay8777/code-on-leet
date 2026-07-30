class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for(int mask = 0; mask < (1<<n); mask++) {
            int xorSum = 0;
            for(int j = 0; j < n; j++) {
                if(mask & (1<<j)) {
                    xorSum ^= nums[j];
                }
            }
            result += xorSum;
        }
        return result;
    }
};
