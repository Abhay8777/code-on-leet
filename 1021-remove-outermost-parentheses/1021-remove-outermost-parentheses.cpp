class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int open = 0;
        
        for(const char& ch : s) {
            if(ch == '(' && open++ > 0) result.push_back(ch);
            if(ch == ')' && --open > 0) result.push_back(ch);
        }
        
        return result;
    }
};