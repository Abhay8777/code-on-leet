class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int result = 0;
        int currSum = 0;
        mp[0] = 1;
        for(int &num: nums){
            currSum+= num;
            int remaning_sum = currSum -goal;
            if(mp.find(remaning_sum)!=mp.end()){
                result+=mp[remaning_sum];
            }
            mp[currSum]++;
            
        }
        return result;
    }
};