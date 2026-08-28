
class Solution {
public:

    string makePalindrome(string half, char mid, int n) {
        string ans = half;

        // Middle character for odd length
        if (n % 2)
            ans += mid;

        // Mirror the first half
        for (int i = (int)half.size() - 1; i >= 0; i--)
            ans += half[i];

        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        int m = n / 2;

        // Count characters
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        // A palindrome can have at most one odd frequency
        int odd = 0;
        char mid = 0;

        for (int c = 0; c < 26; c++) {
            if (freq[c] % 2) {
                odd++;
                mid = char('a' + c);
            }
        }

        if (odd > 1)
            return "";

        // Frequency available for the left half
        vector<int> halfFreq(26);

        for (int c = 0; c < 26; c++)
            halfFreq[c] = freq[c] / 2;


        // --------------------------------------------------
        // Step 1:
        // Try to make left half exactly equal to target's
        // left half.
        // --------------------------------------------------

        string targetHalf = target.substr(0, m);

        vector<int> cnt = halfFreq;
        bool possible = true;

        for (char c : targetHalf) {
            int x = c - 'a';

            if (cnt[x] == 0) {
                possible = false;
                break;
            }

            cnt[x]--;
        }

        // If targetHalf itself is possible,
        // construct its palindrome.
        if (possible) {

            string candidate = makePalindrome(
                targetHalf, mid, n
            );

            // It might already be greater than target
            if (candidate > target)
                return candidate;
        }


        // --------------------------------------------------
        // Step 2:
        // Find the smallest half permutation strictly
        // greater than targetHalf.
        // --------------------------------------------------

        for (int i = m - 1; i >= 0; i--) {

            // Rebuild remaining characters
            vector<int> remaining = halfFreq;

            // Match targetHalf[0 ... i-1]
            bool ok = true;

            for (int j = 0; j < i; j++) {

                int x = targetHalf[j] - 'a';

                if (remaining[x] == 0) {
                    ok = false;
                    break;
                }

                remaining[x]--;
            }

            if (!ok)
                continue;


            // At position i, choose the smallest
            // character strictly greater than targetHalf[i]
            int x = targetHalf[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (remaining[c] == 0)
                    continue;

                string half;

                // Prefix equal to target
                for (int j = 0; j < i; j++)
                    half += targetHalf[j];

                // Make this position larger
                half += char('a' + c);
                remaining[c]--;

                // Fill rest as small as possible
                for (int ch = 0; ch < 26; ch++) {
                    while (remaining[ch] > 0) {
                        half += char('a' + ch);
                        remaining[ch]--;
                    }
                }

                return makePalindrome(half, mid, n);
            }
        }

        return "";
    }
};
