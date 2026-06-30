class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count_zeros = 0;   
        int currSum = 0;       
        int count = 0;
        int i = 0, j = 0;
        while (j < nums.size()) {
            currSum += nums[j];
            while (i < j && (nums[i] == 0 || currSum > goal)) {
                if (nums[i] == 1) {
                    count_zeros = 0;
                } else {
                    count_zeros += 1;
                }
                currSum -= nums[i];
                i++;
            }
            if (currSum == goal) {
                count += 1 + count_zeros;
            }
            j++;
        }
        return count;
    }
};
