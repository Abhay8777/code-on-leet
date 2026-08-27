class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        // Try every possible position from right to left
        // where we make the answer greater than target.
        for (int i = n - 1; i >= 0; i--) {

            // Characters needed for target[0 ... i-1]
            vector<int> cnt = freq;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (cnt[x] == 0) {
                    possible = false;
                    break;
                }

                cnt[x]--;
            }

            if (!possible)
                continue;

            // At position i, choose the smallest character
            // strictly greater than target[i].
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                string ans;

                // Equal prefix
                for (int j = 0; j < i; j++)
                    ans += target[j];

                // Greater character
                ans += char('a' + c);
                cnt[c]--;

                // Remaining characters in sorted order
                for (int ch = 0; ch < 26; ch++) {
                    while (cnt[ch] > 0) {
                        ans += char('a' + ch);
                        cnt[ch]--;
                    }
                }

                return ans;
            }
        }

        return "";
    }
};