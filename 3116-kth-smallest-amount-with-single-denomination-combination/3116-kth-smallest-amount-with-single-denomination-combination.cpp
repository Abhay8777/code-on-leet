class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        
        int n = coins.size();

        auto count = [&](long long x) -> long long {
            long long total = 0;

            // Inclusion-Exclusion
            for (int mask = 1; mask < (1 << n); mask++) {

                long long lcm = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = gcd(lcm, (long long)coins[i]);
                        lcm = lcm / g * coins[i];

                        // LCM is already bigger than x
                        if (lcm > x) {
                            valid = false;
                            break;
                        }
                    }
                }

                if (!valid)
                    continue;

                long long ways = x / lcm;

                if (bits & 1)
                    total += ways;
                else
                    total -= ways;
            }

            return total;
        };

        // Binary search for kth amount
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};