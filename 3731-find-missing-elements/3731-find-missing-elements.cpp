class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int min = nums[0];
        int max = nums[n-1];
        unordered_set<int> s(nums.begin(), nums.end());
        for(int val = min + 1; val < max; val++) {
            if(!s.count(val)) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};
