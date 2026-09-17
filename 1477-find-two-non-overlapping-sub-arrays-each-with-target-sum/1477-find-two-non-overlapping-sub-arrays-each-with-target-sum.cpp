class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        int currSum = 0;

        int i = 0;
        int j = 0;

        vector<int> minBestTillIdx(n, INT_MAX);
        int minLen = INT_MAX;
        int result = INT_MAX;

        while(j < n) {
            currSum += arr[j];

            while(i < j && currSum > target) {
                currSum -= arr[i];
                i++;
            }

            if(currSum == target) {
                int len = j - i + 1;

                if(i > 0 && minBestTillIdx[i-1] != INT_MAX) {
                    result = min(result, len + minBestTillIdx[i-1]);
                }

                minLen = min(minLen, len);
            }
            minBestTillIdx[j] = minLen;
            j++;
        }

        return result == INT_MAX ? -1 : result;

    }
};