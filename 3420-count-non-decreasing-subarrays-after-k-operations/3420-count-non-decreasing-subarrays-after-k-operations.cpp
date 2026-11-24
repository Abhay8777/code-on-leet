class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        deque<pair<int,int>> dq; // {value, count}
        long long ans = 0;
        long long cost = 0;

        int r = n - 1;

        for (int l = n - 1; l >= 0; --l) {
            int cnt = 1;

            while (!dq.empty() && dq.back().first < nums[l]) {
                auto [val, freq] = dq.back();
                dq.pop_back();

                cnt += freq;
                cost += 1LL * (nums[l] - val) * freq;
            }

            dq.push_back({nums[l], cnt});

            while (cost > k) {
                auto [val, freq] = dq.front();
                dq.pop_front();

                cost -= (long long)(val - nums[r]);
                r--;

                if (freq > 1) {
                    dq.push_front({val, freq - 1});
                }
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};