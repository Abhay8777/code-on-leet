class Solution {
public:
    string reverseParentheses(string s) {
        string res;
        stack<int> st;

        for(char ch : s)
        {
            if(ch == '(')
            {
                st.push(res.size());
            }
            else if(ch == ')')
            {
                int len = st.top();
                st.pop();
                reverse(begin(res) + len, end(res));
            }
            else
            {
                res += ch;
            }
        }
        return res;
    }
};