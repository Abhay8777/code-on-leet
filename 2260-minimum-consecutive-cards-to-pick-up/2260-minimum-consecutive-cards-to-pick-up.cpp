class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> freq;
        int n = cards.size();
        int ans = INT_MAX;
        int i = 0, j = 0;
        while(j< n) {
            freq[cards[j]]++;
            while(freq[cards[j]] > 1) {
                ans = min(ans, j - i + 1);
                freq[cards[i]]--;
                i++;
            }
            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }

};