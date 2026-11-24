class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 2;
        int prod = 1;

        while (j < n) {
            // jab tak nums[j] window se clash kare, left se nikalo
            while (__gcd(prod, nums[j]) != 1) {
                prod /= nums[i];
                i++;
            }

            prod *= nums[j];                 // nums[j] ko window mein daalo
            ans = max(ans, j - i + 1);       // window ki length
            j++;                             // right aage badhao
        }
        return ans;
    }
};