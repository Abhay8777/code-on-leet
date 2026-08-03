class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string ans ="";
        for(string x: words){
            ans+=x;
            if(ans==s) return true;
            if(ans.size()>s.size()) break;
        }
        return false;
    }
};