class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st(begin(nums),end(nums));
        int ans =0;
        unordered_map<int, int>mp;
        int i = 0, j=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()==st.size()){
                ans+=(n-j);
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};