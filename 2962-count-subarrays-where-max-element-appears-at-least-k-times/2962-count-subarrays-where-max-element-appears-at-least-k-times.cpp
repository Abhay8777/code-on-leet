class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int count = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] == maxVal) count++;

            while (count >= k) {
                ans += (n - r);  
                if (nums[l] == maxVal) count--;
                l++;
            }
        }
        return ans;
    }
};
