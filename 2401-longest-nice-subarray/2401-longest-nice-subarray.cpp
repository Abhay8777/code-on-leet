class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = 1;
        for(int i = 0;i<n;i++){
            int firstOp = 0;// pahela 0 ke sath cheeck;
            for(int j= i; j<n; j++){
                if((firstOp&nums[j])!=0){
                    break;
                }
                result =max(result, j-i+1);
                firstOp = (firstOp | nums[j]);
            }
        }
        return result;
    }
};