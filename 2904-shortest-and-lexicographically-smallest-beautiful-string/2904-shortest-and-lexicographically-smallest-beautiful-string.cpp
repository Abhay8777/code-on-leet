class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;
        int n = s.size();
        
        // collect positions of '1'
        for(int i = 0; i < n; i++){
            if(s[i] == '1') ones.push_back(i);
        }
        
        if((int)ones.size() < k) return ""; // not enough ones
        
        int minLen = n+1;
        vector<string> candidates;
        
        // sliding window over positions of ones
        for(int i = 0; i + k - 1 < (int)ones.size(); i++){
            int start = ones[i];
            int end = ones[i + k - 1];
            int len = end - start + 1;
            
            if(len < minLen){
                minLen = len;
                candidates.clear();
                candidates.push_back(s.substr(start, len));
            } else if(len == minLen){
                candidates.push_back(s.substr(start, len));
            }
        }
        
        // lexicographically smallest among candidates
        string ans = candidates[0];
        for(auto &c : candidates){
            if(c < ans) ans = c;
        }
        return ans;
    }
};
