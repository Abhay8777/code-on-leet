class Solution {
public:
    static int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> afterSorted(nums);

        auto lambda = [](int num1, int num2) {
            int num1DigitSum = getDigitSum(num1);
            int num2DigitSum = getDigitSum(num2);

            if (num1DigitSum != num2DigitSum) {
                return num1DigitSum < num2DigitSum;
            }

            return num1 < num2;
        };

        sort(begin(afterSorted), end(afterSorted), lambda);

        unordered_map<int, int> valToIdx;

        for (int i = 0; i < n; i++) {
            valToIdx[nums[i]] = i;
        }

        int swapCount = 0;
        for (int i = 0; i < n; i++) {
            int expectedVal = afterSorted[i];
            int currVal     = nums[i];

            if (currVal == expectedVal) continue;

            int expectedIdx = valToIdx[expectedVal];

            nums[i]               = expectedVal;
            nums[expectedIdx]     = currVal;
            valToIdx[expectedVal] = i;
            valToIdx[currVal]     = expectedIdx;

            swapCount++;
        }

        return swapCount;
    }
};