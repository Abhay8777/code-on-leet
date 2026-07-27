class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size()-1;
        sort(begin(nums),end(nums));
        return (nums[n]-1)*(nums[n-1]-1);
    }
};