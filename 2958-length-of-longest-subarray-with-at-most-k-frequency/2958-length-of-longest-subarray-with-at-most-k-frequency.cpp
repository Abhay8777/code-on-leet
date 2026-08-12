class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int i = 0;
        int j = 0;
        int result = 0;
        int extra = 0;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]==k+1){
                extra++;
            }
            if(extra>0){
                mp[nums[i]]--;
                if(mp[nums[i]]==k){
                    extra--;
                }
                i++;
            }
            if(extra == 0){
                result = max(result,j-i+1);
            }
            j++;
        }
        return result;
    }
};