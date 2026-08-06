class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.length();
        unordered_set<char>st;
        
        int count = 0;
        int i =0, j =0;
        while(j<n){
            if(!st.count(s[j])){
                st.insert(s[j]);
                count = max(count, j - i + 1);  // because sub aaray
                j++;
            }
            else{
                
                st.erase(s[i]);
                i++;
            }
        }
        return count;
    }
};