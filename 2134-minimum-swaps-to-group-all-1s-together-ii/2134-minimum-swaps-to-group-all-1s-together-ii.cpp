class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = count(nums.begin(), nums.end(), 1);
        if (totalOnes == 0 || totalOnes == n) return 0;

        vector<int> arr = nums;
        arr.insert(arr.end(), nums.begin(), nums.end());

        int currOnes = 0, maxOnes = 0;
        int i = 0;

        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] == 1) currOnes++;
            while (j - i + 1 > totalOnes) {
                if (arr[i] == 1) currOnes--;
                i++;
            }

            if (j - i + 1 == totalOnes) {
                maxOnes = max(maxOnes, currOnes);
            }
        }

        return totalOnes - maxOnes;
    }
};
