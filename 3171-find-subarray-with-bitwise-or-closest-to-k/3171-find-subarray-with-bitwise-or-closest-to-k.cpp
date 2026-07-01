class Solution {
public:
    void updateFreq(int operation, int val, vector<int> &freq) {
        int i = 0;
        while (val > 0) {
            if (val & 1) {
                freq[i] += operation;
            }
            val >>= 1;
            i++;
        }
    }

    int buildOR(vector<int> &freq) {
        int Or = 0;
        for (int b = 0; b < 32; b++) {
            if (freq[b] > 0) {
                Or |= (1 << b);
            }
        }
        return Or;
    }

    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> freq(32, 0);

        int i = 0, j = 0;
        int result = INT_MAX;

        while (j < n) {

            updateFreq(1, nums[j], freq);

            int Or = buildOR(freq);

            result = min(result, abs(k - Or));

            if (result == 0)
                return 0;

            while (i <= j && Or > k) {

                updateFreq(-1, nums[i], freq);
                i++;

                if (i > j)
                    break;          // Don't consider empty window

                Or = buildOR(freq);

                result = min(result, abs(k - Or));

                if (result == 0)
                    return 0;
            }

            j++;
        }

        return result;
    }
};