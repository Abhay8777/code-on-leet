class Solution {
public:
    void updateFreq(int op, int val, vector<int>& freqBits) {
        int i = 0;
        while (val > 0) {
            if (val & 1)
                freqBits[i] += op;
            val >>= 1;
            i++;
        }
    }

    int minimumDifference(vector<int>& nums, int k) {
        vector<int> freqBits(32, 0);

        int n = nums.size();
        int i = 0, j = 0;
        int result = INT_MAX;
        int windowOr = 0;

        while (j < n) {

            if (i > j)
                windowOr = 0;

            windowOr |= nums[j];
            updateFreq(1, nums[j], freqBits);

            result = min(result, abs(k - windowOr));

            if (result == 0)
                return 0;

            while (i <= j && windowOr > k) {

                updateFreq(-1, nums[i], freqBits);
                i++;

                if (i > j) {
                    windowOr = 0;
                    break;
                }

                windowOr = 0;
                for (int b = 0; b < 32; b++) {
                    if (freqBits[b] > 0)
                        windowOr |= (1 << b);
                }

                result = min(result, abs(k - windowOr));

                if (result == 0)
                    return 0;
            }

            j++;
        }

        return result;
    }
};