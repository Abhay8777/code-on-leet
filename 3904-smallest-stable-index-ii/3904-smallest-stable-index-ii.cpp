class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>suffixMin(n);
        suffixMin[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--) suffixMin[i] = min(suffixMin[i+1], nums[i]);
        int bada_baye = INT_MIN;
        for(int i=0; i<n; i++){
            bada_baye = max(bada_baye, nums[i]);
            if(bada_baye <= suffixMin[i]+k) return i;
        }
        return -1;
    }
};