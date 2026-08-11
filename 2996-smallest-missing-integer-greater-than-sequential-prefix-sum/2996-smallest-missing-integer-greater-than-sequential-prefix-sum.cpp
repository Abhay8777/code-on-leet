class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int prefSum=nums[0];
        int i =1;
        while(i<n && nums[i]==nums[i-1]+1){
            prefSum+=nums[i];
            i++;
        }
        unordered_set<int> s(nums.begin(), nums.end());
        while(s.count(prefSum)){
            prefSum++;
        }
        return prefSum;
    }
};