class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        // Helper lambda to calculate digit sum
        auto digitSum = [](int x) {
            int sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            return sum;
        };

        // Traverse array
        for (int i = 0; i < nums.size(); i++) {
            if (digitSum(nums[i]) == i) {
                return i;  // smallest index mil gaya
            }
        }
        return -1;  // koi match nahi mila
    }
};
