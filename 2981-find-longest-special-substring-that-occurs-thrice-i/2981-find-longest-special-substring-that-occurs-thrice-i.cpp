class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> freq;
        int n = s.size();
        int l = 0;
        while (l < n) {
            int r = l;
            string temp = "";
            while (r < n && s[r] == s[l]) {
                temp += s[r];
                freq[temp]++;
                r++;
            }
            l++;
        }
        int ans = -1;
        for (auto &it : freq) {
            if (it.second >= 3) {
                ans = max(ans, (int)it.first.size());
            }
        }
        return ans;
    }
};