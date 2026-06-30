class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int count = 0;
        int i =0, j = 0;
        while(j<n){
            if(nums[j] == maxVal) count++;
            while(count>=k){
                ans+=n-j;
                if(nums[i]==maxVal) count--;
                i++;
            }
            j++;
        }
        return ans;
    }
};