class Solution {
public:
    typedef long long ll;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        ll result = 0;
        ll currwindow = 0;
        unordered_set<int>st;
        int i =0, j=0;
        while(j<n){
            while(st.count(nums[j])){
                currwindow-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            currwindow+= nums[j];
            st.insert(nums[j]);
            if(j-i+1==k){
                result = max(result, currwindow);
                currwindow-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
};