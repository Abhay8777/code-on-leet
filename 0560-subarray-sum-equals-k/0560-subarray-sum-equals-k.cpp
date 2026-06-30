class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int currSum = 0;
        int result = 0;
        mp[0] = 1;
        for(int &num:nums){
            currSum+=num;
            int remaning_sum = currSum - k;
            if(mp.find(remaning_sum)!=mp.end()){
                result+=mp[remaning_sum];
            }
            mp[currSum]++;
        }
        return result;
    }
};